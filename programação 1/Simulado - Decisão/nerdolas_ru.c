#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

int main() {
    //Ryan, Filipe, Ruan, Heron.
    char escolha_ryan_1;
    char escolha_filipe_1;
    char escolha_ruan_1;
    char escolha_heron_1;
    char escolha_ryan_2;
    char escolha_filipe_2;
    char escolha_ruan_2;
    char escolha_heron_2;
    int valor_a;
    int valor_b;
    int valor_c;
    int valor_d;
    int valor_e;
    int valor_i;
    int valor_j;
    int valor_k;
    int valor_l;
    int valor_m;
    
    scanf(" %c %c %c %c", &escolha_ryan_1, &escolha_filipe_1, &escolha_ruan_1, &escolha_heron_1);
    scanf(" %c %c %c %c", &escolha_ryan_2, &escolha_filipe_2, &escolha_ruan_2, &escolha_heron_2);

    scanf("%d %d %d %d %d", &valor_a, &valor_b, &valor_c, &valor_d, &valor_e);
    scanf("%d %d %d %d %d", &valor_i, &valor_j, &valor_k, &valor_l, &valor_m);
    
    int contador_ryan = 0;
    int contador_filipe = 0;
    int contador_ruan = 0;
    int contador_heron = 0;

    char array[5] = {'a', 'b', 'c', 'd', 'e'};
    char array2[5] = {'i', 'j', 'k', 'l', 'm'};
    int array3[5] = {valor_a, valor_b, valor_c, valor_d, valor_e};
    int array4[5] = {valor_i, valor_j, valor_k, valor_l, valor_m};

    int i;
    for (size_t i = 0; i < 5; i++)
    {
        if (escolha_ryan_1 == array[i]){
            contador_ryan += array3[i];
        } 
         if (escolha_filipe_1 == array[i]){
            contador_filipe += array3[i];
        } 
         if (escolha_ruan_1 == array[i]){
            contador_ruan += array3[i];
        } 
         if (escolha_heron_1 == array[i]){
            contador_heron += array3[i];
        }
    }
    
    for (size_t i = 0; i < 5; i++)
    {
        if (escolha_ryan_2 == array2[i]){
            contador_ryan *= array4[i];
        } 
         if (escolha_filipe_2 == array2[i]){
            contador_filipe *= array4[i];
        } 
         if (escolha_ruan_2 == array2[i]){
            contador_ruan *= array4[i];
        } 
         if (escolha_heron_2 == array2[i]){
            contador_heron *= array4[i];
        }
    }
    
    // printf("%d\n%d\n%d\n%d\n", contador_ryan, contador_filipe, contador_ruan, contador_heron);

    
    contador_ryan %= 100;
    contador_filipe %= 100;
    contador_ruan %= 100;
    contador_heron %= 100;
    
    //FULANO 10 - VENCEDOR
    //CICLANO 8 - PERDEDOR

    //ORGANIZAR QUEM GANHO ARHHHHHHHHHHHHHHHHHH
    int val[4] = {contador_ryan, contador_filipe, contador_ruan, contador_heron};
    char *nomes[4] = {"Ryan", "Filipe", "Ruan", "Heron"};

    int vencedor = 0;
    int perdedor = 0;

    for (size_t i = 0; i < 4; i++)
    {
        if(val[i] > val[vencedor]){
            vencedor = i;
        }
        
        if(val[i] < val[perdedor]){
            perdedor = i;
        }

    }
    
    printf("%s %d - Vencedor\n%s %d - Perdedor", nomes[vencedor], val[vencedor], nomes[perdedor], val[perdedor]);

	return 0;

}
