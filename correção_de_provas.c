#include <stdio.h>

void ler_gabarito(int contador, char array[], int tamanho){
  if(contador == 0){
    return;
  }
  char letra;
  scanf(" %c", &letra);
  array[tamanho] = letra;
  ler_gabarito(--contador, array, ++tamanho);
}

void printar_aprovacao(float notas[], int tamanho, int contador, int aprovados){
  if(tamanho == contador){
    printf("%.1lf%\n", aprovados / (tamanho / 100.0));
    return;
  }
  if(notas[contador] >= 6){
    ++aprovados;
  }
  printar_aprovacao(notas, tamanho, ++contador, aprovados);
}

void comparar_arryas(int contador, int tamanho, char array1[], char array2[], float resultado, int aluno, float notas[]){
  if(contador == tamanho){
    notas[aluno - 1] = resultado;
    printf("%d %.1f\n", aluno, resultado);
    return;
  }
  if(array1[contador] == array2[contador]){
    ++resultado;
  }
  comparar_arryas(++contador, tamanho, array1, array2, resultado, aluno, notas);
}

float mais_repetido(float array[], int tamanho) {
    int maior_contagem = 0;
    float numero_mais_repetido = array[0];

    for (int i = 0; i < tamanho; i++) {
        int contagem = 0;

        for (int j = 0; j < tamanho; j++) {
            if (array[i] == array[j]) {
                contagem++;
            }
        }

        if (contagem > maior_contagem) {
            maior_contagem = contagem;
            numero_mais_repetido = array[i];
        }
    }

    printf("%.1f", numero_mais_repetido);
    return; 
}


void print_nota(char gabarito[], float notas[], int contador_alunos){
  int aluno;
  scanf("%d", &aluno);
  if(aluno == 9999){
    printar_aprovacao(notas, contador_alunos, 0, 0);
    mais_repetido(notas, contador_alunos);
    return;
  }
  char gabarito_aluno[10];
  ler_gabarito(10, gabarito_aluno, 0);
  comparar_arryas(0, 10, gabarito_aluno, gabarito, 0.00, aluno, notas);
  print_nota(gabarito, notas, ++contador_alunos);
}



int main()
{
  char gabarito[10];
  float notas[99];
  ler_gabarito(10, gabarito, 0);
  print_nota(gabarito, notas, 0);
}