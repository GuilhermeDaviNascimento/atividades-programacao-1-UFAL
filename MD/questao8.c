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
    int a, b, m;
    printf("xa ≡ b mod m\n");
    printf("Digite a, b e m:\n");
    scanf("%d %d %d", &a, &b, &m);

    int inverso = inverso_mod(a, m);

    if (inverso == -1) {
        printf("Não existe solução unica.\n");
    } else {
        int x = (inverso * b) % m;
        printf("x ≡ %d (mod %d)\n", x, m);
    }

    return 0;
}