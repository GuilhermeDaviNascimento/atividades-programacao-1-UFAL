#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

int main() {
    int estilo_p, estilo_s;
    float nota;
    scanf("%d%d%f", &estilo_p, &estilo_s, &nota);

    if ((estilo_p == 1 || estilo_p == 3) && estilo_s == 1){
        printf("Aumenta mais!\n");
    }
    if ((estilo_p == 1 || estilo_p == 3) && estilo_s == 2){
        printf("Legal\n");
    }

    if (estilo_p == 2 && estilo_s == 1){
        printf("Essa eh punk\n");
    }
    if (estilo_p == 2 && estilo_s == 2){
        printf("Hoje eu choro\n");
    }

    if (nota >= 1 && nota <= 4){
        printf(":'(\n");
    } else if (nota > 4 && nota <= 7){
        printf("^_^\n");
    } else if (nota > 7 && nota <= 10){
        printf("=D\n");
    }

	return 0;
}