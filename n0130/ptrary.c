#include <stdio.h>
int main(){
int *x[3];
int a=48,b=49,c=50;
x[0]=&a;
x[1]=&b;
x[2]=&c;
printf("%d\n",*x[0]);
printf("%d\n",*x[1]);
printf("%d\n",*x[2]);

}