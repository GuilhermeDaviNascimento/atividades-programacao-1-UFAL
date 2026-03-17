#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

int main() {
    //tarifa = valor fixo + preço por quilômetro x quilômetros rodados.
    //Você receberá 4 valores reais, relativos a, respectivamente, o salário de Pedro, valor fixo da tarifa, 
    //preço por quilômetro e a quilometragem a ser percorrida.
    //Em seguida, se Pedro for viajar no fim de semana, receberá o inteiro 1, caso contrário, o 0.
    float salario, tarifa, preco_km, kms;
    int fds;
    scanf("%f%f%f%f%d", &salario, &tarifa, &preco_km, &kms, &fds);

    float valor_corrida = tarifa + preco_km * kms;

    if (fds == 1){
        valor_corrida*=1.1;
    }

    float limite = salario * 0.3;

    if (salario * 0.3 >= valor_corrida){
        printf("Vai poder viajar.\n");
        printf("%.2f\n", valor_corrida);
        printf("%.2f\n", limite - valor_corrida);
    } else {
        printf("Não vai poder viajar.\n");
        printf("%.2f\n", valor_corrida - limite);
    }
	return 0;
}
