#include <stdio.h>
#include <stdlib.h>

int main()
{
    //short *arr = malloc(sizeof(short)*5);
    u_int32_t arr[] = {0x15641716, 0x45056517, 0x54215503, 0x54124504};
    u_int32_t a = 0x12345678;
    //for (int i = 0; i < 5; i++) arr[i] = i;
    /*
    printf("%p\n", arr);
    int a = 1;
    printf("%p\n", arr+a);
    */
    short *p = &arr;
    printf("%x\n", &arr[0]);
    printf("%x\n", &arr[1]);  //+4
    printf("%x\n", p);       //
    printf("%x\n", (p+1));
    return 0;
}
