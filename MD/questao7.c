#include <stdio.h>

int euclides_estendido(int a, int b, int *x, int *y) {
    if (b == 0) {
        *x = 1;
        *y = 0;
        return a;
    }

    int x1, y1;

    int mdc = euclides_estendido(b, a % b, &x1, &y1);

    *x = y1;
    *y = x1 - (a / b) * y1;

    return mdc;
}

int inverso_mod(int a, int b) {
    int x, y;

    int mdc = euclides_estendido(a, b, &x, &y);

    if (mdc != 1) {
        return -1;
    }

    return (x % b + b) % b;
}

int main() {
    int a, b;
    printf("a mod b\n");
    printf("Digite a e b:\n");

    scanf("%d %d", &a, &b);

    int inverso = inverso_mod(a, b);

    if (inverso == -1) {
        printf("O inverso nao existe.\n");
    } else {
        printf("O inverso de %d mod %d é %d\n", a, b, inverso);
    }

    return 0;
}