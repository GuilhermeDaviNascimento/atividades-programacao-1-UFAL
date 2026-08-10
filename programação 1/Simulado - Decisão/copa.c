#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

int main() 
{
    //N   I  S  VI
    char nacionalidade, sexo;
    int idade;
    float valor_ingresso;
    scanf(" %c%d %c%f", &nacionalidade, &idade, &sexo, &valor_ingresso);

    if (idade < 0 || idade >= 120)
    {
        printf("idade invalida!");
        return 0;
    }

    if ((nacionalidade == 'F' || nacionalidade == 'C') && idade < 21)
    {
        printf("nao pode comprar");
        return 0;
    }

    if (nacionalidade == 'B')
    {
        valor_ingresso = valor_ingresso/2;
    } else if (nacionalidade == 'A' && idade < 18)
    {
        valor_ingresso = valor_ingresso - (valor_ingresso*0.2);
    } else if (nacionalidade == 'A' && sexo == 'F')
    {
        valor_ingresso = valor_ingresso - (valor_ingresso*0.2);
    } else if ((nacionalidade == 'F' || nacionalidade == 'C'))
    {
        valor_ingresso = valor_ingresso - (valor_ingresso*0.3);
    } else if ((nacionalidade == 'I' || nacionalidade == 'R') && idade < 16)
    {
        valor_ingresso = valor_ingresso - (valor_ingresso*0.4);
    } else if ((nacionalidade == 'I' || nacionalidade == 'R') && idade >= 16)
    {
        valor_ingresso = valor_ingresso - (valor_ingresso*0.3);
    } else if (sexo == 'F')
    {
        valor_ingresso = valor_ingresso - (valor_ingresso*0.1);
    }

    printf("R$ %.2f", valor_ingresso);
	return 0;
}