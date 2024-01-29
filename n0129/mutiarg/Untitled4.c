
#include <stdio.h>
#include <stdarg.h>

void x(int a, int b, ...)
{
    printf("%d\n",a);
    va_list y;
    va_start(y,b);
    for(int i = 0; i < b ; i++)
    {
        int z = va_arg(y,int);
        printf("%d",z);
    }
    va_end(y);
}

void y(char* fmt , ...){
va_list z;
va_start(z,fmt);
vprintf(fmt,z);
va_end(z);
}

int main()
{
    //x(48,3,7,8,9);
    //printf("===\n");
    y("abc%d,%lf,%s;\n",48,78.95,"ttp");
}
