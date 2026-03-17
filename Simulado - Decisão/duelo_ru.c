#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

int main() {
    int classe1, classe2, classe3, classe4, classe5, classe6;
    double ataque1, ataque2, ataque3, ataque4, ataque5, ataque6;
    double vida1, vida2, vida3, vida4, vida5, vida6;

    scanf("%d %lf %lf", &classe1, &ataque1, &vida1);
    scanf("%d %lf %lf", &classe2, &ataque2, &vida2);
    scanf("%d %lf %lf", &classe3, &ataque3, &vida3);

    scanf("%d %lf %lf", &classe4, &ataque4, &vida4);
    scanf("%d %lf %lf", &classe5, &ataque5, &vida5);
    scanf("%d %lf %lf", &classe6, &ataque6, &vida6);

    //DUELO 1
    if (classe1 == 1 && classe4 == 3)
    {
        vida1 *= 1.3;
    }
    else if (classe4 == 1 && classe1 == 3)
    {
        vida4 *= 1.3;
    }

    if (classe1 == 3 && classe4 == 2)
    {
        ataque1 *= 1.25;
    }
    else if (classe4 == 3 && classe1 == 2)
    {
        ataque4 *= 1.25;
    }

    if (classe1 == 2 && classe4 == 1)
    {
        ataque1 *= 1.15;
        vida1 *= 1.15;
    }
    else if (classe4 == 2 && classe1 == 1)
    {
        ataque4 *= 1.15;
        vida4 *= 1.15;
    }

    //DUELO 2
    if (classe2 == 1 && classe5 == 3)
    {
        vida2 *= 1.3;
    }
    else if (classe5 == 1 && classe2 == 3)
    {
        vida5 *= 1.3;
    }

    if (classe2 == 3 && classe5 == 2)
    {
        ataque2 *= 1.25;
    }
    else if (classe5 == 3 && classe2 == 2)
    {
        ataque5 *= 1.25;
    }

    if (classe2 == 2 && classe5 == 1)
    {
        ataque2 *= 1.15;
        vida2 *= 1.15;
    }
    else if (classe5 == 2 && classe2 == 1)
    {
        ataque5 *= 1.15;
        vida5 *= 1.15;
    }

    //DUELO 3
    if (classe3 == 1 && classe6 == 3)
    {
        vida3 *= 1.3;
    }
    else if (classe6 == 1 && classe3 == 3)
    {
        vida6 *= 1.3;
    }

    if (classe3 == 3 && classe6 == 2)
    {
        ataque3 *= 1.25;
    }
    else if (classe6 == 3 && classe3 == 2)
    {
        ataque6 *= 1.25;
    }

    if (classe3 == 2 && classe6 == 1)
    {
        ataque3 *= 1.15;
        vida3 *= 1.15;
    }
    else if (classe6 == 2 && classe3 == 1)
    {
        ataque6 *= 1.15;
        vida6 *= 1.15;
    }

    int vencedor_1 = 0, vencedor_2 = 0, vencedor_3 = 0;

    //DUELO 1
    if (vida1 <= vida4)
    {
        vida4 -= ataque1;
        if (vida4 > 0)
        {
            vida1 -= ataque4;
        }
    }
    else
    {
        vida1 -= ataque4;
        if (vida1 > 0)
        {
            vida4 -= ataque1;
        }
    }

    if (vida1 <= 0 && vida4 > 0)
    {
        vencedor_1 = 2;
    }
    else if (vida4 <= 0 && vida1 > 0)
    {
        vencedor_1 = 1;
    }
    else if (vida1 > vida4)
    {
        vencedor_1 = 1;
    }
    else if (vida4 > vida1)
    {
        vencedor_1 = 2;
    } else if (vida4 == vida1)
    {
        if (ataque1 > ataque4)
        {
            vencedor_1 = 1;
        }
        else
        {
            vencedor_1 = 2;
        }
    }

    //DUELO 2
    if (vida2 <= vida5)
    {
        vida5 -= ataque2;
        if (vida5 > 0)
        {
            vida2 -= ataque5;
        }
    }
    else
    {
        vida2 -= ataque5;
        if (vida2 > 0)
        {
            vida5 -= ataque2;
        }
    }

    if (vida2 <= 0 && vida5 > 0)
    {
        vencedor_2 = 2;
    }
    else if (vida5 <= 0 && vida2 > 0)
    {
        vencedor_2 = 1;
    }
    else if (vida2 > vida5)
    {
        vencedor_2 = 1;
    }
    else if (vida5 > vida2)
    {
        vencedor_2 = 2;
    } else if (vida5 == vida2)
    {
        if (ataque2 > ataque5)
        {
            vencedor_2 = 1;
        }
        else
        {
            vencedor_2 = 2;
        }
    }

    //DUELO 3
    if (vida3 <= vida6)
    {
        vida6 -= ataque3;
        if (vida6 > 0)
        {
            vida3 -= ataque6;
        }
    }
    else
    {
        vida3 -= ataque6;
        if (vida3 > 0)
        {
            vida6 -= ataque3;
        }
    }

    if (vida3 <= 0 && vida6 > 0)
    {
        vencedor_3 = 2;
    }
    else if (vida6 <= 0 && vida3 > 0)
    {
        vencedor_3 = 1;
    }
    else if (vida3 > vida6)
    {
        vencedor_3 = 1;
    }
    else if (vida6 > vida3)
    {
        vencedor_3 = 2;
    } else if (vida6 == vida3)
    {
        if (ataque3 > ataque6)
        {
            vencedor_3 = 1;
        }
        else
        {
            vencedor_3 = 2;
        }
    }

    int contador_pedro = 0, contador_tulio = 0;
    int array[3] = {vencedor_1, vencedor_2, vencedor_3};

    for (size_t i = 0; i < 3; i++)
    {
        if (array[i] == 1)
        {
            printf("Rodada%d: Pedro\n", i + 1);
            contador_pedro++;
        }
        else if (array[i] == 2)
        {
            printf("Rodada%d: Tulio\n", i + 1);
            contador_tulio++;
        }
    }

    if (contador_pedro > contador_tulio)
    {
        printf("Pedro vitorioso\n");
    }
    else
    {
        printf("Tulio vitorioso\n");
    }

    return 0;
}