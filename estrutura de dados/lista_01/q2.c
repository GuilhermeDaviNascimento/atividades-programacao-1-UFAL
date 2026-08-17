// 2) Considere uma “espiral triangular” que parte da origem das coordenadas e passa consecutivamente nos pontos (1, 0), (1, 1), (-2, -1), (3, -1) (2, 2), (-4, -2), (5, -2), (3, 3),
// (-6,-3), (7, -3), (4, 4), etc. Com este processo, a espiral tocará todos os pontos de coordenadas inteiras (x,x). Com este processo também, podemos “numerar”. O ponto inicial (0, 0) é
//  o ponto 0, o ponto (1, 0) é o ponto 1, etc. Faça um programa para determinar as coordenadas de um ponto n dados.

// (0, 0) entrada 0
// (1, 0) entrada 1

// (1, 1) -3 -2
// (-2, -1) +5 (o dobro +1) 0
// (3, -1) -1 +3

// (2, 2) -6 -4
// (-4, -2) +9 (o dobro +1) 0
// (5, -2) -2 +5

// (3, 3) -9 -6
// (-6,-3) o dobro +1 e 0
// (7, -3) -3 +7

// (4, 4)

#include <stdio.h>

void espiral(int start_1, int start_2, int stop)
{
    int etapa = 1;

    int i1 = -3;
    int i2 = -2;

    int k1 = -1;
    int k2 = 3;

    for (int i = 0; i < stop; i++)
    {
        if(i + 1 == stop){
            printf("(%d, %d)\n", start_1, start_2);
            return; 
        }

        if (start_1 == 0 && start_2 == 0)
        {
            start_1 = 1;
        }
        else if (start_1 == 1 && start_2 == 0)
        {
            start_2 = 1;
        }

        if (i > 1)
        {
            if (etapa == 1)
            {
                start_1 = start_1 + i1;
                start_2 = start_2 + i2;

                i1 = i1 - 3;
                i2 = i2 - 2;
                etapa++;
            }
            else if (etapa == 2)
            {   
                start_1 = (start_1 * -1) + 1;
                etapa++;
            }
            else if (etapa == 3)
            {
                start_1 = start_1 + k1;
                start_2 =  start_2 + k2;
                k1 = k1 - 1;
                k2 = k2 + 2;
                etapa = 1;
            }
        }
    }
}

int main()
{
    espiral(0, 0, 12);
    return 0;
}