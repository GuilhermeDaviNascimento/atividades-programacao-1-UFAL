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
    // caso o array inteiro esteja vazio
    int vazio = 1;

    for (int i = 0; i < size; i++)
    {
        if (array[i] != -1)
        {
            vazio = 0;
            break;
        }
    }

    if (vazio)
    {
        array[0] = number;
        return;
    }

    // encontrar a primeira posição que não é -1
    int primeiro = 0;

    while (array[primeiro] == -1)
    {
        primeiro++;
    }

    // caso o novo número seja menor que o primeiro elemento valido
    if (number <= array[primeiro])
    {
        if (primeiro > 0)
        {
            array[primeiro - 1] = number;
        }
        else
        {
            for (int k = primeiro + 1; k < size; k++)
            {
                if (array[k] == -1)
                {
                    array[k] = number;
                    bubble_sort(array, primeiro, k);
                    return;
                }
            }
        }
    }
    else
    {
        for (int i = primeiro; i < size; i++)
        {
            if (array[i] != -1 && array[i] < number)
            {
                for (int j = i; j < size; j++)
                {
                    if (array[i] != -1 && array[j] > number)
                    {
                        for (int k = j; k > primeiro; k--)
                        {
                            if (array[k] == -1)
                            {
                                array[k] = number;
                                bubble_sort(array, k, j);
                                return;
                            }
                            else if (k - 1 > primeiro && array[k - 1] != -1)
                            {
                                for (int l = j; l < size; l++)
                                {
                                    if (array[l] == -1)
                                    {
                                        array[l] = number;
                                        bubble_sort(array, j, l);
                                        return;
                                    }
                                }
                            }
                        }
                        return;
                    }

                    // tratar quando não existir número maior
                    else if (j + 1 == size)
                    {
                        for (int k = j; k > primeiro; k--)
                        {
                            if (array[k] == -1)
                            {
                                array[k] = number;
                                bubble_sort(array, k, j);
                                return; // CORREÇÃO
                            }
                        }
                    }
                }
            }

            break;
        }
    }
}

void remover(int array[], int size, int number)
{
    if(number < 0){
        printf("Número inválido.\n");
        return;
    }
    // conferir se o elemento esta no array
    int achou = 0;
    for (int i = 0; i < size; i++)
    {
        if (array[i] == number)
        {
            achou = 1;
            break;
        }
    }
    if (!achou)
    {
        printf("Elemento não encontrado no array.");
    }
    else
    {
        for (int i = 0; i < size; i++)
        {
            if (array[i] == number)
            {
                array[i] = -1;
                break;
            }
        }
    }
}

int main()
{
    int array[20] = {
        -1, 2, -1, 5, -1, -1, 9, -1, 12, -1, -1, 15, -1, 16, -1, -1, 17, -1, 20, -1
    };

    int size = sizeof(array) / sizeof(array[0]);
    int opcao;
    int number;

    do
    {
        printf("\n============================\n");
        printf("        MENU PRINCIPAL\n");
        printf("============================\n");
        printf("1 - Inserir número\n");
        printf("2 - Remover número\n");
        printf("0 - Sair\n");
        printf("============================\n");
        printf("Escolha uma opção: ");
        scanf("%d", &opcao);

        switch (opcao)
        {
            case 1:
                printf("\nDigite o número para inserir: ");
                scanf("%d", &number);

                inserir(array, size, number);

                printf("\nArray após a inserção:\n");
                for (int i = 0; i < size; i++)
                {
                    printf("%d ", array[i]);
                }
                printf("\n");

                break;

            case 2:
                printf("\nDigite o número para remover: ");
                scanf("%d", &number);

                remover(array, size, number);

                printf("\nArray após a remoção:\n");
                for (int i = 0; i < size; i++)
                {
                    printf("%d ", array[i]);
                }
                printf("\n");

                break;

            case 0:
                printf("\nPrograma encerrado.\n");
                break;

            default:
                printf("\nOpção inválida! Escolha 0, 1 ou 2.\n");
                break;
        }

    } while (opcao != 0);

    return 0;
}