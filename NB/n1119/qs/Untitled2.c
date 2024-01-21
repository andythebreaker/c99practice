//ch04-05.c
#define PLEASE_SORT {90,32,76,1,4,60,58,11,12,93}
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
void inputarr(int*,int);
void showdata(int*,int);
void quick(int*,int,int,int);
int process=0;
int main(void)
{
    int size=10;
    int data[]=PLEASE_SORT;
    showdata(data,size);
}
void showdata(int data[], int size)
{
    int i;
    for(i=0; i<size; i++)
    {
        printf("%3d",data[i]);
    }
    printf("\n");
}
void quick(ind d[],int size,int lf,int rg){
int i,j,tmp;
int lf_idx;
int rg_idx;
int t;
if(lf<rg){//?->
    lf_idx=lf+1;
    rg_idx=rg;
}//?<-
step2:
    printf("[process %d]=>",process++);
    for(t=0;t<size;t++){
        printf("[%2d]",d[t]);
    }
}
