#include <iostream>

using namespace std;

int **plus1(int **);

int main()
{
    int **arr, **b;
    arr = new int*[2];
    for(int i = 0;i < 3;i++)
    {
        arr[i] = new int[3];
    }
    
    for(int i = 0;i < 2;i++)
    {
        for(int j = 0;j < 3;j++)
        {
            arr[i][j] = i*0+j;
        }
    }
    cout << **arr << endl;
    
    arr = plus1(arr);
    
    cout << **arr << endl;
    
    delete [] arr;
    return 0;
}


int **plus1(int **a)
{
    int **p = new int*[2];
    for(int i = 0;i < 3;i++)
    {
        p[i] = new int[3];
    }
    
    for(int i = 0;i < 2;i++)
    {
        for(int j = 0;j < 3;j++)
        {
            p[i][j] = a[i][j]+1;
        }
    }
    return p; 
}
