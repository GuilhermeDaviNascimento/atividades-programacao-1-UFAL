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

void questao8(int a, int b, int m)
{
    // int a, b, m;
    // printf("xa ≡ b mod m\n");
    // printf("Digite a, b e m:\n");
    // scanf("%d %d %d", &a, &b, &m);
    // Lê os valores de a, b e m

    int inverso = inverso_mod(a, m);
    // Calcula o inverso de a módulo m usando a funcao

    if (inverso == -1)
    {
        // Se não existir inverso, não há solução única
        printf("A congruencia nao possui inverso modular.\n");
    }
    else
    {
        int x = (inverso * b) % m;
        // Resolve a congruência ax ≡ b (mod m)
        // Multiplica b pelo inverso de a
        printf("x ≡ %d (mod %d)\n", x, m);
    }

}