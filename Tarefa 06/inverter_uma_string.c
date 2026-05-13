#include <stdio.h>

void inputs()
{
    char letra;

    if (scanf("%c", &letra) != 1 || letra == '\n')
    {
        return;
    }

    inputs();

    printf("%c", letra);

    // printf("%c", letra);
    // inputs();
    // para printar em ordem normal
}

int main()
{
    inputs();
    return 0;
}