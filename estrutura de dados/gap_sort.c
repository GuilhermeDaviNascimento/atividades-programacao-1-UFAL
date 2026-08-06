#include <stdio.h>

void bubble_sort(int array[], int inicio, int fim)
{
    int temp;

    for (int i = inicio; i < fim; i++)
    {
        for (int j = inicio; j < fim - (i - inicio); j++)
        {
            if (array[j] > array[j + 1])
            {
                temp = array[j];
                array[j] = array[j + 1];
                array[j + 1] = temp;
            }
        }
    }
}

void inserir(int array[], int size, int number)
{
    // Caso o novo número seja menor ou igual ao primeiro elemento válido do vetor.
    // Nesse caso, ele será inserido na primeira posição livre (-1)
    // e depois será ordenado até a posição correta.
    if (array[0] != -1 && number <= array[0])
    {
        // Procura a primeira posição vazia.
        for (int k = 1; k < size; k++)
        {
            if (array[k] == -1)
            {
                // Insere o número na posição vazia.
                array[k] = number;

                // Ordena apenas o trecho necessário.
                bubble_sort(array, 0, k);
                break;
            }
        }
    }

    // Percorre o vetor procurando um número menor que o valor a ser inserido.
    for (int i = 0; i < size; i++)
    {
        if (array[i] != -1 && array[i] < number)
        {
            // A partir desse ponto, procura um elemento maior que o número.
            for (int j = i; j < size; j++)
            {
                // Encontrou um número maior que o valor que será inserido.
                if (array[i] != -1 && array[j] > number)
                {
                    // Procura uma posição vazia voltando de j até o início.
                    for (int k = j; k > 0; k--)
                    {
                        if (array[k] == -1)
                        {
                            // Coloca o novo número na posição vazia.
                            array[k] = number;

                            // Ordena somente o intervalo onde ocorreu a inserção.
                            bubble_sort(array, k, j);
                            break;
                        }
                    }
                    break;
                }
                // Caso tenha chegado ao final do vetor sem encontrar
                // um elemento maior que o número.
                // Isso significa que ele deve ser colocado no final
                // da sequência ordenada.
                else if (j + 1 == size)
                {
                    // Procura uma posição vazia voltando do final.
                    for (int k = j; k > 0; k--)
                    {
                        if (array[k] == -1)
                        {
                            // Insere o número.
                            array[k] = number;

                            // Ordena apenas o trecho correspondente.
                            bubble_sort(array, k, j);
                            break;
                        }
                    }
                }
            }
        }

        // Interrompe após a primeira iteração do laço externo.
        break;
    }

    // Imprime o vetor após a tentativa de inserção.
    for (int i = 0; i < size; i++)
    {
        printf("%d, ", array[i]);
    }
    printf("\n");
}

int main()
{
    int array[7] = {1, -1, -1, 5, -1, -1, 6};
    int size = sizeof(array) / sizeof(array[0]);
    inserir(array, size, 2);
    inserir(array, size, 9);
    inserir(array, size, 3);
    inserir(array, size, 0);
}
