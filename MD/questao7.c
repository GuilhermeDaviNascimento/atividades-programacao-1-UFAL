#include <stdio.h>


int euclides_estendido(int a, int b, int *x, int *y)
// Função do Algoritmo de Euclides Estendido
{
    // Caso base da recursão:
    if (b == 0)
    // Quando b = 0, o MDC é a
    {
        *x = 1;
        *y = 0;
        return a;
    }

    int x1, y1;
    // Variáveis auxiliares para armazenar os coeficientes da chamada recursiva

    int mdc = euclides_estendido(b, a % b, &x1, &y1);
    // Chamada recursiva do algoritmo de Euclides Estendido

    *x = y1;
    *y = x1 - (a / b) * y1;
    // Atualização dos coeficientes x e y com base na recursão

    return mdc;
}

int inverso_mod(int a, int b)
// Função que calcula o inverso modular de a módulo b
{
    int x, y;

    int mdc = euclides_estendido(a, b, &x, &y);
    // Calcula o MDC e os coeficientes de Bézout

    if (mdc != 1)
    {
        // Se o MDC não for 1, não existe inverso modular
        return -1;
    }

    return (x % b + b) % b;
}

int main() {
    int a, b;
    printf("a mod b\n");
    printf("Digite a e b:\n");

    scanf("%d %d", &a, &b);
    // Lê os dois valores digitados pelo usuário e armazena em a e b

    int inverso = inverso_mod(a, b);
    // Chama a função que calcula o inverso modular de a em relação a b

    if (inverso == -1) {
        // Verifica se o inverso não existe (caso MDC(a, b) != 1)
        printf("O inverso nao existe.\n");
    } else {
        // Se existir inverso modular, imprime o resultado
        printf("O inverso de %d mod %d é %d\n", a, b, inverso);
    }

    return 0;
}