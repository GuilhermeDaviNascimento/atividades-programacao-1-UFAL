#include <stdio.h>

void printar_maior(int array[], int comeco, int fim, int maior)
{
    if (comeco == fim) {
        printf("%d\n", maior);
        return;
    }

    if (array[comeco] > maior) {
        maior = array[comeco];
    }

    printar_maior(array, comeco + 1, fim, maior);
}

void printar_menor(int array[], int comeco, int fim, int menor)
{
    if (comeco == fim) {
        printf("%d\n", menor);
        return;
    }

    if (array[comeco] < menor) {
        menor = array[comeco];
    }

    printar_menor(array, comeco + 1, fim, menor);
}

void inputs(int array[], int tamanho)
{
    int num;

    if (scanf("%d", &num) != 1) {

        if (tamanho > 0) {
            printar_maior(array, 0, tamanho, array[0]);
            printar_menor(array, 0, tamanho, array[0]);
        }

        return;
    }

    array[tamanho] = num;

    inputs(array, tamanho + 1);
}

int main()
{
    int array[100];

    inputs(array, 0);

    return 0;
}