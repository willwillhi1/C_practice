#include <stdio.h>
using namespace std;

void swap(int &x, int &y)  
{
    int temp = x;
    x = y;
    y = temp;
    return;
}

int main()
{   
    //value
    int a = 1;
    int b = 100;
    printf("Before: a = %d, b = %d\n",a,b);
    swap(a, b);                             // (int &x = a)，x,a point to same address
    printf("After: a = %d, b = %d\n",a,b);
    
    //pointer
    int m = 1,n = 100;
    int *c = &m;
    int *d = &n;
    printf("Before: c = %d, d = %d\n",*c,*d);
    swap(*c, *d);                             
    printf("After: c = %d, d = %d\n",*c,*d);
}
