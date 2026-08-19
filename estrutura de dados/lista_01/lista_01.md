1) Faça um programa que exibe na tela os elementos de uma série de fibonacci de forma imperativa e recursiva, depois calcule a complexidade de cada algoritmo.

#include <stdio.h>

void fibonacci ( int i, int j, int parada ) {
    if(parada == 0){
        return;
    } else if (i + j == 0){
        printf("%d\n", i + j);
        return fibonacci(i, j + 1, parada - 1);
    } else {
        printf("%d\n", i + j);
        return fibonacci(j, j + i, parada - 1);
    }
}

int main(){
    fibonacci(0, 0, 10);
    return 0;
}

2) Considere uma “espiral triangular” que parte da origem das coordenadas e passa consecutivamente nos pontos (1, 0), (1, 1), (-2, -1), (3, -1) (2, 2), (-4, -2), (5, -2), (3, 3),
(-6,-3), (7, -3), (4, 4), etc. Com este processo, a espiral tocará todos os pontos de coordenadas inteiras (x,x). Com este processo também, podemos “numerar”. O ponto inicial (0, 0) é
o ponto 0, o ponto (1, 0) é o ponto 1, etc. Faça um programa para determinar as coordenadas de um ponto n dados.


#include <stdio.h>

void espiral(int start_1, int start_2, int stop)
{
    int etapa = 1;

    int i1 = -3;
    int i2 = -2;

    int k1 = -1;
    int k2 = 3;

    for (int i = 0; i < stop; i++)
    {
        if(i + 1 == stop){
            printf("(%d, %d)\n", start_1, start_2);
            return; 
        }

        if (start_1 == 0 && start_2 == 0)
        {
            start_1 = 1;
        }
        else if (start_1 == 1 && start_2 == 0)
        {
            start_2 = 1;
        }

        if (i > 1)
        {
            if (etapa == 1)
            {
                start_1 = start_1 + i1;
                start_2 = start_2 + i2;

                i1 = i1 - 3;
                i2 = i2 - 2;
                etapa++;
            }
            else if (etapa == 2)
            {   
                start_1 = (start_1 * -1) + 1;
                etapa++;
            }
            else if (etapa == 3)
            {
                start_1 = start_1 + k1;
                start_2 =  start_2 + k2;
                k1 = k1 - 1;
                k2 = k2 + 2;
                etapa = 1;
            }
        }
    }
}

int main()
{
    espiral(0, 0, 12);
    return 0;
}

3) Exercícios do livro página 88 questão 3.12 e 3.9; página 88 questão 3.12

3.12 Determine Θ for the following code fragments in the average case. Assume
that all variables are of type int.
(a) a = b + c;
    d = a + e;

(b) sum = 0;
        for (i=0; i<3; i++)
            for (j=0; j<n; j++)
                sum++;

(c) sum=0;
    for (i=0; i<n*n; i++)
        sum++;  

(d) for (i=0; i < n-1; i++)
        for (j=i+1; j < n; j++) {
            tmp = A[i][j];
            A[i][j] = A[j][i];
            A[j][i] = tmp;
        }

(e) sum = 0;
    for (i=1; i<=n; i++)
        for (j=1; j<=n; j*=2)
            sum++;

(f) sum = 0;
    for (i=1; i<=n; i*=2)
        for (j=1; j<=n; j++)
            sum++;

(a) Θ(1) → o algoritmo executa uma quantidade constante de operações, independentemente de n.
(b) Θ(n) → há um for que percorre n vezes. O for externo executa apenas 3 vezes, que é uma constante.
(c) Θ(n²) → o for executa n × n = n² vezes.
(d) Θ(n²) → há dois for aninhados juntos eles realizam aproximadamente n²/2 iterações.
(e) Θ(n log n) → o for externo executa n vezes e o interno usa j *= 2, portanto executa log n vezes.
(f) Θ(n log n) → o for externo usa i *= 2, executando log n vezes, enquanto o interno executa n vezes.

3.9 (a) What is the smallest integer k such that √n = O(n**k)?
(b) What is the smallest integer k such that n log n = O(n**k)?

a) podemos escrever como √n ​= n**1/2, logo n**1/2 = O(n**k), como k deve ser um inteiro e precisa ser maior ou igual a 1/2, o menor inteiro que satisfaz essa condição é k = 1.
b) testando valores, temos que para 1 → n log n > n, logo não é verdade. Testando o 2 n log n = O(n**2), pois log n = O(n) e por consequencia n log n = O(n⋅n) = O(n**2), logo 2 é o menor inteiro.