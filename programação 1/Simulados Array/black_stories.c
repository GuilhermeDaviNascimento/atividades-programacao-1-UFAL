#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

void popular_array(int array[], int contador, int tamanho){
    if(contador == tamanho) return;
    array[contador] = 0;
    popular_array(array, ++contador, tamanho);
}

void conferir_casas_suspeitas(int array[], int suspeitos_incial, int suspeitos_final){
    if(suspeitos_incial > suspeitos_final) return;
    array[suspeitos_incial] = array[suspeitos_incial] + 1;
    conferir_casas_suspeitas(array, ++suspeitos_incial, suspeitos_final);
}

void conferir_intervalo(int qnt, int pontos[]){
    if (qnt == 0) return;
    int suspeitos_incial, suspeitos_final;
    scanf("%d%d", &suspeitos_incial, &suspeitos_final);
    conferir_casas_suspeitas(pontos, suspeitos_incial, suspeitos_final);
    conferir_intervalo(qnt - 1, pontos);
}

void bubble(int v[], int n, int i) {
    if (n == 1) return;
    if (i == n - 1) { bubble(v, n - 1, 0); return; }
    if (v[i] > v[i + 1]) {
        int temp = v[i];
        v[i] = v[i + 1];
        v[i + 1] = temp;
    }
    bubble(v, n, i + 1);
}

// Dado que pontos[i] == maior, percorre até o fim da sequência contígua
// e retorna o índice do último elemento da sequência
int percorrer(int pontos[], int tam, int i, int maior) {
    if (i == tam) return i - 1;
    if (pontos[i] == maior) return percorrer(pontos, tam, i + 1, maior);
    return i - 1;
}

// Imprime cada bloco contíguo de elementos com valor máximo
void imprimir_blocos(int pontos[], int tam, int i, int maior) {
    if (i == tam) return;
    if (pontos[i] == maior) {
        int fim = percorrer(pontos, tam, i, maior);
        printf("%d %d\n", i, fim);
        imprimir_blocos(pontos, tam, fim + 1, maior);
    } else {
        imprimir_blocos(pontos, tam, i + 1, maior);
    }
}

void imprimir_sequencias(int pontos[], int tam, int i, int maior,
                         int maior_seq, int melhor_comeca, int melhor_termina) {
    if (i == tam) {
        printf("maior sequencia: %d\n", maior_seq);
        printf("comeca em: %d\n", melhor_comeca);
        printf("termina em: %d\n", melhor_termina);
        return;
    }
    if (pontos[i] == maior) {
        int fim = percorrer(pontos, tam, i, maior);
        int tamanho_seq = fim - i + 1;
        if (tamanho_seq > maior_seq) {
            maior_seq = tamanho_seq;
            melhor_comeca = i;
            melhor_termina = fim;
        }
        imprimir_sequencias(pontos, tam, fim + 1, maior, maior_seq, melhor_comeca, melhor_termina);
    } else {
        imprimir_sequencias(pontos, tam, i + 1, maior, maior_seq, melhor_comeca, melhor_termina);
    }
}

void imprimir_pontos(int pontos[], int contador, int tamanho){
    if(contador == tamanho) return;
    if(contador > 0) printf(" ");
    printf("%d", pontos[contador]);
    imprimir_pontos(pontos, contador + 1, tamanho);
}

int main() {
    int numero_suspeitos, numero_testemunhas;
    scanf("%d%d", &numero_suspeitos, &numero_testemunhas);

    int pontos[numero_suspeitos];
    popular_array(pontos, 0, numero_suspeitos);
    conferir_intervalo(numero_testemunhas, pontos);

    int array_clone[numero_suspeitos];
    memcpy(array_clone, pontos, sizeof(pontos));
    bubble(array_clone, numero_suspeitos, 0);

    int maior = array_clone[numero_suspeitos - 1];

    imprimir_pontos(pontos, 0, numero_suspeitos);
    printf("\n");
    printf("%d\n", maior);

    imprimir_blocos(pontos, numero_suspeitos, 0, maior);
    imprimir_sequencias(pontos, numero_suspeitos, 0, maior, 0, 0, 0);

    return 0;
}