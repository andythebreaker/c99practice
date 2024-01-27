#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <stddef.h>
#include <math.h>


void show(int *q, int Qs)
{
    for(int i = 0; i < Qs; i++)
    {
        printf("%3d",q[i]);
    }
    printf("\n");
}

bool isDiagonal(int target_x,int target_y,int ref_x,int ref_y)
{
    return abs(target_x-ref_x)==abs(target_y-ref_y);
}

bool issafe(int *q,int x, int y)
{
    int i =0 ;
    while(i<x)
    {
        if(q[i]==y||isDiagonal(x,y,i,q[i]))
        {
            return false;
        }
        i++;
    }
    return true;
}

void decide_position(int *q,int Qs,int x,int *ans)
{
    int y=0;
    while(y<Qs)
    {
        if(issafe(q,x,y))
        {
            q[x]=y;
            if(x==Qs-1)
            {
                (*ans)++;
                show(q,Qs);
            }
            else
            {
                decide_position(q,Qs,x+1,ans);
            }
        }
        y++;
    }
}

void initQ(int **q,int Qs)
{
    *q = (int*)malloc(sizeof(int)*Qs);
    for(int i = 0; i < Qs; i++)
    {
        (*q)[i]=0;
    }
}


int main()
{
//Q原型:<----->:x軸; it's value is where it's Q is true (exist)
    int Q=8;
    int *q=NULL;
    int ans=0;
    initQ(&q,Q);//!importamt 做2層指標去傳址
    decide_position(q,Q,0,&ans);
    printf("\n<<<%d>>>\n",ans);
}
