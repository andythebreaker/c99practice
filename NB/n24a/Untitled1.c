#include <stdio.h>
#include <string.h>

typedef struct y{
    int a;
    char b;
} z;

int main(){
    z o1;
    o1.a=48;
    o1.b='e';
    printf("<%c>", o1.b);
}
