
#include <stdio.h>
#define testdata "data1.txt"
const unsigned long SIZE = 9999;
void line(char*,int,int);
int main(void)
{
    int N;
    char part1[100000];
    char part2[100000];
    int start, end;
    int i;
    unsigned long j;
    unsigned long count;
    FILE *fp;

    fp=fopen(testdata,"r");
    fscanf(fp,"%d",&N);
    fscanf(fp,"%d %d",&start,&end);
    line(part1,start,end);
    for(i=1; i<=N-1; i++)
    {
        fscanf(fp,"%d %d",&start,&end);
        line(part2,start,end);
        for(j=0; j<SIZE; j++)
        {
            if(part1[j]=='Y'||part2[j]=='Y')
                part1[j]='Y';
        }
    }
    count=0;
    int index=0;
    while(index<SIZE)
    {
        if(part1[index]=='Y')
        {
            count++;
        }
        index++;
    }
    printf("%d",count);
    fclose(fp);
    return 0;
}

void line(char segment[100000],int start,int end){
unsigned long j;
for(j=start;j<end;j++){
    segment[j]='Y';
}
}
