#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include <float.h>
#include <errno.h>
#include <stdlib.h>
#include "Untitled5.h"
#define NL printf("\n");
int bucket_PUSH(char* bucket,int s,char c)
{
    *(bucket+(s-1))=c;
    char* TMP_PTR=(char*)realloc(bucket,sizeof(char)*(s+1));
    if(!TMP_PTR)
    {
        printf("malloc fail!\n");
        exit(EXIT_FAILURE);
    }
    else
    {
        bucket=TMP_PTR;
    }
    return ++s;
}
char symbol[]=SYMBOL;
double calculate_polynomial(char* p,int x)
{
    printf("check if global?\n");
    printf("%c %c %c %c %c \n",symbol[0],symbol[1],symbol[2],symbol[3],symbol[4]);
    char* ptr=p;
    double y=0.0;
    char* bucket_symbol=(char*)malloc(sizeof(char)*1);
    char* bucket_nums=(char*)malloc(sizeof(char)*1);
    int size_bucket_symbol=1;
    int size_bucket_nums=1;
    while(*ptr!='\0')
    {
        if((*ptr)==symbol[0]||(*ptr)==symbol[1]||(*ptr)==symbol[2]||(*ptr)==symbol[3]||(*ptr)==symbol[4])
        {
            size_bucket_symbol=bucket_PUSH(bucket_symbol,size_bucket_symbol,*ptr);
            for(int i=0; i<size_bucket_symbol-1; i++)
            {
                printf("%c, ",bucket_symbol[i]);
            }
            NL
        }
        else
        {
            size_bucket_nums=bucket_PUSH(bucket_nums,size_bucket_nums,*ptr);
            for(int i=0; i<size_bucket_nums-1; i++)
            {
                printf("%c, ",bucket_nums[i]);
            }
            NL
        }
        ptr++;
    }
    return y;
}
