#include <stdio.h>


void printararray(int array[], int lenght, int contador_zero){
  if(contador_zero == lenght){
    return;
  }
  printf("%d ", array[contador_zero]);
  printararray(array, lenght, ++contador_zero);
}


void inputs(int n, int array[], int lenght)
{
  if(n == 0)
  {
    printararray(array, lenght + 1, 1);
    return;
  }
  int a;
  scanf("%d", &a);
  array[n] = a;
  inputs(n - 1, array, lenght);
}

int main()
{
  int n1;
  scanf("%d", &n1);
  int array[n1];
  inputs(n1, array, n1);
}