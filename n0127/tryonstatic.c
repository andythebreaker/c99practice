#include <stdio.h>
#include <stdlib.h>
#include <stddef.h>
int tryfcn(){
    static int a = 0;
    a++;
    return a;
}
int main(){
    for (size_t i = 0; i < 7; i++)
    {
        printf("%d\n",tryfcn());
    }
    
}