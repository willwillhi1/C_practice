#include <stdio.h>
#include <stdlib.h>

int swap(int *a, int *b) 
{
    int tmp = *a;
    *a = *b;
    *b = tmp;
}

int partition(int *arr, int front, int end) 
{
    int pivot = end;
    int i = front - 1;
    int j = front;
    while (j != end) 
    {
        if (arr[j] < arr[pivot]) 
        {
            i++;
            swap(arr+i, arr+j);
        }
        j++;
    }
    i++;
    swap(arr+i, arr+pivot);
    return i;
}

void quicksort(int *arr, int front, int end) 
{
    if (front < end) 
    {
        int pivot = partition(arr, front, end);
        quicksort(arr, front, pivot-1);
        quicksort(arr, pivot+1, end);
    }
}

int main()
{
    int arr[] = {4, 1, 9, 6, 7, 3, 8, 2, 5};
    quicksort(&arr[0], 0, 8);
    for (int i = 0; i < 9; i++) 
    {
        printf("%d ", arr[i]);
    }

    return 0;
}
