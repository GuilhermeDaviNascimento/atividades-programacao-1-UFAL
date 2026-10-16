#include <stdio.h>

int main()
{
    int list[5] = {5, 4, 2, 1, 3};
    int size = sizeof(list) / sizeof(list[0]);
    for (int i = 1; i < size; i++)
    {
        int chave = list[i];
        int j = i - 1;

        while (j >= 0 && list[j] < chave)
        {
            list[j + 1] = list[j];
            j--;
        }

        list[j + 1] = chave;
    }

    for (int i = 0; i < size; i++)
    {
        printf("%d, ", list[i]);
    }
    printf("\n");
}

// for (int i = 0; i < size; i++)
// {
//     printf("%d, ", list[i]);
// }
// printf("\n");