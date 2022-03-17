#include <stdio.h>
#include <stdlib.h>

void merge(int *arr, int l, int m, int r)
{
    int l_size = m-l+1;
    int r_size = r-m;
    //printf("***\n");
    int *L = malloc(l_size*sizeof(int));
    int *R = malloc(r_size*sizeof(int));
    //int L[l_size], R[r_size];
    
    for (int i = 0; i < l_size; i++)
        L[i] = arr[l+i];
    for (int i = 0; i < r_size; i++)
        R[i] = arr[i+m+1];
    /*
    for (int i = 0; i < l_size; i++)
        printf("%d\n", L[i]);
    */    
    int i = 0, j = 0, k = 0;
    for (k = l; i < l_size && j < r_size; k++)
    {
        if (L[i] < R[j])
        {
            arr[k] = L[i];
            i++;
        }
        else
        {
            arr[k] = R[j];
            j++;
        }
    }
    while (i < l_size)
    {
        arr[k] = L[i];
        i++;
        k++;
    }
    while (j < r_size)
    {
        arr[k] = R[j];
        j++;
        k++;
    }
    free(L);
    free(R);
}

void mergesort(int *arr, int l, int r)
{
    if (l < r) 
    {
        //printf("***\n");
        
        int m = (r+l)/2;
        mergesort(arr, l, m);
        mergesort(arr, m+1, r);
        merge(arr, l, m, r);
    }
}


void printArray(int *A, int size)
{
    int i;
    for (i = 0; i < size; i++)
        printf("%d ", A[i]);
    printf("\n");
}

int main()
{
    int arr[] = { 12, 11, 13, 5, 6, 7 };
    int arr_size = sizeof(arr) / sizeof(arr[0]);
  
    printf("Given array is \n");
    printArray(arr, arr_size);
  
    mergesort(arr, 0, arr_size - 1);
  
    printf("\nSorted array is \n");
    printArray(arr, arr_size);
    return 0;
}
