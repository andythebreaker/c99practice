#include <stdio.h>
#include <limits.h>
#include <math.h>

int main()
{
    unsigned int m = UINT_MAX;
    double x = 0;
    int i = 0;
    while(x<((double)m)){
        x=pow(2,(double)i);
        i++;
    }
    printf("<%d>\n",--i);

    printf("<%u>", UINT_MAX);
}
