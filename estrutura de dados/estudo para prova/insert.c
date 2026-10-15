#include <stdio.h>

int main(){
    int list[5] = {5, 4, 2, 1, 3};
    int size = sizeof(list)/sizeof(list[0]);
    for (int i = 0; i < size; i++)
    {
        for (int j = 0; j < size; j++)
            {
                if(list[i] < list[j]){
                    int temp = list[i];
                    list[i] = list[j];
                    list[j] = temp;
                }
            }
    }

    for (int i = 0; i < size; i++)
    {
        printf("%d \n", list[i]);
    }
    
}