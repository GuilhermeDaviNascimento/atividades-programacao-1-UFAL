#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

int main() {
    int v1, v2, v3, v4;
    char l1, l2, l3, l4;
    int a, b, c, d;

    scanf("%d %d %d %d", &v1, &v2, &v3, &v4);
    scanf(" %c %c %c %c", &l1, &l2, &l3, &l4);
    scanf("%d %d %d %d", &a, &b, &c, &d);


    float media = (v1 + v2 + v3 + v4) / 4.0;
    float fator = 0;


    //CALCULAR FATOR AAAAAAAAAARH
    if (media >= 0 && media <= 10){
        fator = 0.4;
    } else if (media > 10 && media <= 30){
        fator = 0.6;
    } else if (media > 30 && media <=60){
        fator = 0.8;
    } else if (media > 60){
        fator = 1;
    }

    char alfabeto[4] = {'a', 'b', 'c', 'd'};
    int valores[4] = {a, b, c, d}; 
    char escolhas[4] = {l1, l2, l3, l4}; 
    int num_escolhido[4] = {v1, v2, v3, v4};

    float resultado[4];

    int i, j;
    for (i = 0; i < 4; i++)
    {
        resultado[i] = 0;
        for (j = 0; j < 4; j++)
        {
            if (escolhas[i] == alfabeto[j]){
                resultado[i] = num_escolhido[i] + valores[j] + (valores[j] * fator);
            }
        }
        
    }
    
    char *nomes[4] = {"Anderson", "Guilherme", "Rita", "Higor"}

    int menor = 0

    for (i = 0; i < count; i++)
    {
        if(resultado[i] < resultado[menor]){
            menor = i
        }
    }
    
 printf("%s quem vai pagar o lanche!:D\n", nomes[menor]);
    
    return 0;
}