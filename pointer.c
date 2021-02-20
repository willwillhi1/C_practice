#include <stdio.h>

int main(){
    int n = 1;
    int *x = &n;
    int **y = &x;
    printf("%d\n",*x);
    printf("%d",**y);
    return 0;
}

//output: 1 
//        1
