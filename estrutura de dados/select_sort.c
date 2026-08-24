#include <stdio.h>

void swap(int array[], int index_1, int index_2){
    int temp;
    temp = array[index_1];
    array[index_1] = array[index_2];
    array[index_2] = temp;
}


void selection_sort(int array[], int tamanho, int contador){

    for (size_t i = 0; i < 5; i++)
    {
        printf("%d ", array[i]);
    }
    printf("\n");

    if(contador == tamanho){
        return;
    }
    int menor = array[contador];
    int menor_indice = contador;
    
    for (size_t i = contador + 1; i < tamanho; i++)
    {
        if(menor > array[i]){
            menor = array[i];
            menor_indice = i;
        }
    }
    swap(array, contador , menor_indice);
    contador++;
    selection_sort(array, tamanho, contador);
}


int main()
{
    int array[5] = {5, 2, 10, 1, 9};

    selection_sort(array, 5, 0);

    // for (size_t i = 0; i < 5; i++)
    // {
    //     printf("%d ", array[i]);
    // }
    
    return 0;
}