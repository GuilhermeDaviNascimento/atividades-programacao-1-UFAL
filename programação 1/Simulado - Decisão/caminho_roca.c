// P1
// ├─ E → P2
// │     ├─ E → P4
// │     │     ├─ E → Pasto
// │     │     └─ D → Abrigo
// │     └─ D → Coucho
// └─ D → P3
//       ├─ E → Estabulo
//       └─ D → Galpao de ordenha

#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

int main() {
    char p1, p2, p3, p4;
    scanf(" %c %c %c %c", &p1, &p2, &p3, &p4);
    if (p1 == 'D'){
        if (p2 == 'D'){
            if(p4 == 'D'){
                printf("Pasto");
                return 0;
            }
            if (p4 == 'E'){
                printf("Abrigo");
                return 0;
            }
        } else {
            printf("Coucho");
            return 0;
        }
    } else {
        if(p3 == 'D'){
            printf("Estabulo");
            return 0;
        } else {
            printf("Galpao de ordenha");
            return 0;
        }
    }
	return 0;
}