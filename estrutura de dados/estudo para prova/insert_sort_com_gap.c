#include <stdio.h>

void insert_gap(int list[], int n, int numero)
{
    int indice_gap;
    int indice_prox_gap = n;
    for (size_t i = 0; i < n; i++)
    {
        if (list[i] == -1)
        {
            list[i] = numero;
            indice_gap = i;
            break;
        }
    }

    for (size_t i = indice_gap; i < n; i++)
    {
        if (list[i] == -1)
        {
            indice_prox_gap = i;
        }
    }

    for (size_t i = indice_gap; i <= indice_prox_gap - 1; i++)
    {

        int chave = list[i];
        int j = i - 1;

        while (j >= 0 && list[j] > chave)
        {
            list[j + 1] = list[j];
            j--;
        }
        list[j + 1] = chave;
    }
}

int main()
{
    int list[6] = {5, -1, 1, -1, 6, -1};
    int n = 6;
    insert_gap(list, n, 2);
    insert_gap(list, n, 7);
    insert_gap(list, n, 1);
    for (size_t i = 0; i < n; i++)
    {
        printf("%d ", list[i]);
    }

    return 0;
}