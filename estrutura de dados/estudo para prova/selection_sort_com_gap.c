#include <stdio.h>

void swap(int list[], int i, int j)
{
    int temp = list[i];
    list[i] = list[j];
    list[j] = temp;
}

void selection_sort_gap(int list[], int n, int num)
{
    int i_gap;
    int i_gap_pro = n;
    for (size_t i = 0; i < n; i++)
    {
        if (list[i] == -1)
        {
            list[i] = num;
            i_gap = i;
            break;
        }
    }
    for (size_t i = i_gap; i < n; i++)
    {
        if (list[i] == -1)
        {
            i_gap_pro = i;
            break;
        }
    }
    
    for (size_t i = 0; i < i_gap_pro; i++)
    {
        int menor = list[i];
        int i_menor = i;

        for (size_t j = i + 1; j < i_gap_pro; j++)
        {
            if (menor > list[j])
            {
                menor = list[j];
                i_menor = j;
            }
        }

        if (i_menor != i)
        {
            swap(list, i, i_menor);
        }
    }
}

int main()
{
    int list[6] = {5, -1, 1, -1, 6, -1};
    int n = 6;

    selection_sort_gap(list, n, 2);
    selection_sort_gap(list, n, 3);
    selection_sort_gap(list, n, 5);
    for (int i = 0; i < n; i++)
    {
        printf("%d, ", list[i]);
    }

    return 0;
}