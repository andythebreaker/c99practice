#include <stdio.h>
#include <stdlib.h>
int y(const void *a, const void *b ){return (*(int*)a)-(*(int*)b);}
int main(){
int x[]={3,5,1,6,4};
qsort(x,5,sizeof(int),&y);
for(int i=0;i<5;i++)printf("%d,",x[i]);
}