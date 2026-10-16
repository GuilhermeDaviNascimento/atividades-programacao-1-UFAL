#include <stdio.h>

int main()
{
    int lista[5] = {5, 4, 2, 1, 3};
    int n = sizeof(lista) / sizeof(lista[0]);

    for (size_t i = 0; i < n; i++)
    {

        int menor = lista[i];
        int menor_indice = i;
        for (size_t j = i + 1; j < n; j++)
        {
            if (lista[j] < menor )
            {
                menor = lista[j];
                menor_indice = j;
            }
        }

        if(menor_indice != i){
            int temp = lista[i];
            lista[i] = menor;
            lista[menor_indice] = temp;
        }

    }

    for (int i = 0; i < n; i++)
    {
        printf("%d, ", lista[i]);
    }
    printf("\n");
}