#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>


// P = 2.75
// M = 3.66
// G = 5.17

// Bermuda = 3.82
// Camisa = 4.55
// Moletom = 7.12


int main() {
    float custo_material;
    scanf("%f", &custo_material);
    char tamanho_roupa, tipo_roupa;
    scanf(" %c %c", &tamanho_roupa, &tipo_roupa);

    float val1 = custo_material;
    float val2 = custo_material;

    if(tamanho_roupa == 'P'){
        val1*=2.75;
    } else if(tamanho_roupa == 'M') {
        val1*=3.66;
    } else if(tamanho_roupa == 'G'){
        val1*=5.17;
    }
    
    if(tipo_roupa == 'B'){
        val2*=3.82;
    } else if(tipo_roupa == 'C') {
        val2*=4.55;
    } else if(tipo_roupa == 'M'){
        val2*=7.12;
    }

    printf("%.2f R$", (val1 + val2) / 2);
    
	return 0;
}