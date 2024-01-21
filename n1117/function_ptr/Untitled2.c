//c99 obj
#include <stdio.h>

typedef struct obj
{
    int x;
    char y;
    void (*add_x)(struct obj *,int);
} obj;

void INIT_add_x(obj *self,int z)
{
    (self->x)+=z;
};

int main()
{
    obj o;
    o.x=123;
    o.y='p';
    o.add_x=INIT_add_x;
    o.add_x(&o,1);
    printf("<%d> <%c>",o.x,o.y);
}
