#include <stdio.h>

void sort_aux(int lista[], int n, int casa)
{
    for (size_t i = 0; i < n; i++)
    {
        int chave = lista[i];
        int j = i - 1;

        if (casa == 0)
        {
            while (j >= 0 && (lista[j] % 10) > (chave % 10))
            {
                lista[j + 1] = lista[j];
                j--;
            }
            lista[j + 1] = chave;
        }
        else if (casa == 1)
        {
            while (j >= 0 && ((lista[j] / 10) % 10) > ((chave / 10) % 10))
            {
                lista[j + 1] = lista[j];
                j--;
            }
            lista[j + 1] = chave;
        }
        else if (casa == 2)
        {
            while (j >= 0 && (lista[j] / 100) > (chave / 100))
            {
                lista[j + 1] = lista[j];
                j--;
            }
            lista[j + 1] = chave;
        }
    }
}

int main()
{
    int lista[6] = {53, 89, 150, 36, 633, 233};
    int n = 6;
    int qnt_algarismos = 3;

    for (size_t i = 0; i < qnt_algarismos; i++)
    {
        for (int i = 0; i < n; i++)
        {
            printf("%d, ", lista[i]);
        }
        printf("\n");

        sort_aux(lista, n, i);
    }

    for (int i = 0; i < n; i++)
    {
        printf("%d, ", lista[i]);
    }
    printf("\n");
    return 0;
}