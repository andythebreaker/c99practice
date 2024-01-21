//tree2
#include <stdio.h>
///problem1 所以數要不要實作上左右?，用linked list?，我先用ary的方法；阿幹，上次是卡在struct 末尾[]
typedef struct o{
int x;
struct o y[];
}o;
typedef o *o_pt;
int main(void){
//o_pt a = (o_pt) malloc()
printf("%d",sizeof(o));
}
