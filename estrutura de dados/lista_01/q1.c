#include <stdio.h>

//1) Faça um programa que exibe na tela os elementos de uma série de fibonacci de forma imperativa e recursiva, depois calcule a complexidade de cada algoritmo.

void fibonacci ( int i, int j, int parada ) {
    if(parada == 0){
        return;
    } else if (i + j == 0){
        printf("%d\n", i + j);
        return fibonacci(i, j + 1, parada - 1);
    } else {
        printf("%d\n", i + j);
        return fibonacci(j, j + i, parada - 1);
    }
}

int main(){
    fibonacci(0, 0, 10);
    return 0;
}