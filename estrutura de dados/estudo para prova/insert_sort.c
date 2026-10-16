#include <stdio.h>

int main()
{
    int lista[5] = {5, 3, 2, 6, 1};
    int n = sizeof(lista) / sizeof(lista[0]);

    for (size_t i = 1; i < n; i++)
    {
        int chave = lista[i];
        int j = i - 1;

        while (j >= 0 && lista[j] > chave)
        {
            lista[j + 1] = lista[j];
            j--;
        }
        lista[j + 1] = chave;
    }
    for (int i = 0; i < n; i++)
    {
        printf("%d, ", lista[i]);
    }
    printf("\n");
    return 0;
}