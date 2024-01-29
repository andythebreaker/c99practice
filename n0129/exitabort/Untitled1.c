#define a true
#include <stdbool.h>
#include <stdio.h>
int main()
{
    printf("hi!");
    int x = 0;
    if(a)
    {
        abort();
    }
    else
    {
        exit(48);
    }
    printf("bye!");
}
