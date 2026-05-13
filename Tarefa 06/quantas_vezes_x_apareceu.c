#include <stdio.h>

void contar_reps (int contador, int array[], int inicio, int repes){
  if(contador == inicio){
    printf("%d", repes);
    return;
  }
  if(array[contador] == array[inicio]){
    ++repes;
  }
  ++inicio;
  contar_reps(contador, array, inicio , repes);
}

void input(int contador, int array[]){
  int n1;
  if(scanf("%d", &n1) != 1){
    contar_reps(contador - 1, array, 0, 0);
    return;
  }
  array[contador] = n1;
  ++contador;
  input(contador, array);
}

int main()
{
  int array[11];
  input(0, array);
}