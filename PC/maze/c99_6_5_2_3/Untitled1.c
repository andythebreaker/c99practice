#include <stdio.h>

int main()
{
    typedef struct S_x
    {
        char a;
        char b;
    } T_x;

    T_x x[3];

    x[0].a='a';
    x[1].a='b';
    x[2].a='c';
    x[0].b='d';
    x[1].b='e';
    x[2].b='f';

    printf("sizeof T_x %d\n",sizeof(T_x));
    printf("sizeof T_x %d\n",sizeof(char));

    printf("x[0].a='%c';x[1].a='%c';x[2].a='%c';\nx[0].b='%c';x[1].b='%c';x[2].b='%c';\n"
           ,x[0].a,x[1].a,x[2].a,x[0].b,x[1].b,x[2].b);
    printf("x[0].a='%c';x[1].a='%c';x[2].a='%c';\nx[0].b='%c';x[1].b='%c';x[2].b='%c';\n"
           ,x->a,(x+sizeof(T_x)*1)->a,(x+sizeof(T_x)*2)->a,x->b,(x+sizeof(T_x)*1)->b,(x+sizeof(T_x)*2)->b);
}
