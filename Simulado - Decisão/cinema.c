#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

// Quantidade total de alunos que irão ao cinema;
// Quantos alunos um supervisor pode cuidar;
// Quantidade planejada de ônibus;
// A capacidade máxima de cada ônibus. 
int main() {
    int q_alunos, q_alunos_por_supervisor, q_onibus, q_lugares_onibus;
    scanf("%d%d%d%d", &q_alunos, &q_alunos_por_supervisor, &q_onibus, &q_lugares_onibus);

    int q_supervisores = (q_alunos + q_alunos_por_supervisor - 1) / q_alunos_por_supervisor;
    int q_lugares = q_onibus * q_lugares_onibus;
    int total = q_supervisores + q_alunos;
    if (q_alunos == 0){
        printf("Davi foi assistir o filme sozinho =(");
        return 0;
    }

    if (total - q_lugares == 0){
        printf("Iremos ao cinema!\n");
        printf("Todas as vagas foram preenchidas.");
    } else if (total - q_lugares > 0){
        printf("Não é possível.\nFalta %d vagas.", (q_alunos + q_supervisores) - q_lugares);
    } else if ((q_alunos + q_supervisores) - q_lugares < 0){
        printf("Iremos ao cinema!\n");
        printf("Vagas Vazias = %d", q_lugares - (q_alunos + q_supervisores));
    } 

	return 0;
}