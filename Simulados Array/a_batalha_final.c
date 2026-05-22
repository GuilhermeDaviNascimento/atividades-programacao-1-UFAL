#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

void popular_array(int qnt, int cartas[], int contador) {
    if (contador >= qnt) return;
    int i;
    scanf("%d", &i);
    cartas[contador] = i;
    popular_array(qnt, cartas, contador + 1);
}

int contar_frequencia(int array[], int tamanho, int alvo, int i, int apareceu) {
    if (i >= tamanho) return apareceu;
    if (array[i] == alvo) apareceu++;
    return contar_frequencia(array, tamanho, alvo, i + 1, apareceu);
}

int calcular_pontos(int array[], int contador, int tamanho, int melhor_val, int melhor_freq) {
    if (contador >= tamanho) return melhor_val;

    int freq = contar_frequencia(array, tamanho, array[contador], 0, 0);

    if (freq > melhor_freq || (freq == melhor_freq && array[contador] > melhor_val)) {
        melhor_val = array[contador];
        melhor_freq = freq;
    }

    return calcular_pontos(array, contador + 1, tamanho, melhor_val, melhor_freq);
}

void input_rodadas(int qnt, int pontucao_pedro, int pontucao_tulio) {
    if (qnt == 0) {
        if (pontucao_pedro > pontucao_tulio) {
            printf("Pedro foi vitorioso com %d pontos", pontucao_pedro);
        } else if (pontucao_tulio > pontucao_pedro) {
            printf("Túlio foi vitorioso com %d pontos", pontucao_tulio);
        } else {
            printf("Túlio e Pedro empataram com %d pontos", pontucao_pedro);
        }
        return;
    }

    int qnt_pedro, qnt_tulio;
    scanf("%d%d", &qnt_pedro, &qnt_tulio);

    int cartas_pedro[qnt_pedro];
    int cartas_tulio[qnt_tulio];
    popular_array(qnt_pedro, cartas_pedro, 0);
    popular_array(qnt_tulio, cartas_tulio, 0);

    int pontos_pedro = calcular_pontos(cartas_pedro, 0, qnt_pedro, 0, 0);
    int pontos_tulio = calcular_pontos(cartas_tulio, 0, qnt_tulio, 0, 0);

    printf("pedro: %d tulio: %d\n", pontos_pedro, pontos_tulio);

    if (pontos_pedro > pontos_tulio) {
        ++pontucao_pedro;
    } else if (pontos_tulio > pontos_pedro) {
        ++pontucao_tulio;
    }

    input_rodadas(qnt - 1, pontucao_pedro, pontucao_tulio);
}

int main() {
    int rodadas;
    scanf("%d", &rodadas);
    input_rodadas(rodadas, 0, 0);
    return 0;
}