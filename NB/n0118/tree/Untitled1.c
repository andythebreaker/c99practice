#include <stdio.h>
#include <stddef.h>
#include <stdlib.h>
typedef struct o
{
    int k;
    struct o *p, *n;
} o;
typedef struct l
{
    int s;
    o h;
    o *e;
    o x[];
} l;
typedef l *y;
int main()
{
    int t[]= {5,3,6,4,7,8,2};
    y z= (y) malloc(sizeof(l)+sizeof(o)*(sizeof(t)/sizeof(int)));
    z.s=(sizeof(t)/sizeof(int));
    z.h.k=-1;
    z.h.p=NULL;
    e=&(z.x[0]);
    for(int i = 0 ; i < z.s; i++)
    {
       if(z.h.k<0) {
            e->k=t[i];
            e++;
            z.h.k=1;
       }else{//我這裡的邏輯寫這樣:比this小就放左子NODE，比this大就放右子NODE
        if (*(e-1)>t[i]){//不是啊那串列可以幹嘛?
e->k=t[i];
(e-1)->n=e;
e++;
        }else{
e->k=t[i];
(e-1)->p=e;
e++;

///這樣排很明顯的，一個父節點只有左子或右子其一有值，顯然不正確
        }
       }
    }
}
