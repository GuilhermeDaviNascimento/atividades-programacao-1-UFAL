#include <stdio.h>
#include <stdlib.h>

typedef struct No
{
    int valor;
    struct No *proximo;
} No;

void inserir_no(No **lista, int valor)
{
    No *novo = malloc(sizeof(No));

    if (novo == NULL)
    {
        printf("Erro na alocação de memória.");
        return;
    }

    novo->valor = valor;
    novo->proximo = NULL;

    if (*lista == NULL)
    {
        *lista = novo;
    }
    else
    {
        No *auxiliar = *lista;
        while (auxiliar->proximo != NULL)
        {
            auxiliar = auxiliar->proximo;
        }
        auxiliar->proximo = novo;
    }
}

void printar_lista(No *lista)
{
    No *auxiliar = lista;
    while (auxiliar != NULL)
    {
        printf("%d -> ", auxiliar->valor);
        auxiliar = auxiliar->proximo;
    }
    printf("NULL\n");
}

void concatenar_listas(No *Lista_1, No *lista_2)
{
    No *auxiliar1 = Lista_1;
    No *auxiliar2 = lista_2;

    while (auxiliar1->proximo != NULL)
    {
        auxiliar1 = auxiliar1->proximo;
    }
    auxiliar1->proximo = auxiliar2;
}

int main()
{
    No *Lista_1 = NULL;
    No *Lista_2 = NULL;
    inserir_no(&Lista_1, 10);
    inserir_no(&Lista_1, 20);
    inserir_no(&Lista_1, 30);
    
    inserir_no(&Lista_2, 40);
    inserir_no(&Lista_2, 50);
    inserir_no(&Lista_2, 60);

    printar_lista(Lista_1);
    printar_lista(Lista_2);


    concatenar_listas(Lista_1, Lista_2);
    printar_lista(Lista_1);
    return 0;
}
