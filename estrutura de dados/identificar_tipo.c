#include <stdio.h>
#include <string.h>

void identificar(char numero[]){
    //strlen(numero) retorna o tamanho da string
    for (int i = 0; i < strlen(numero); i++)
    {
        if(numero[i] == '.'){
        printf("real\n");
        return;
        }
    }
    
    if(numero[0] == '-'){
        printf("negativo\n");
        return;
    } 
    
    printf("natural\n");
}

int main (){
    while(1){
        char numero[20];
        scanf(" %20s", &numero);
        identificar(numero);
    }
    return 0;
}