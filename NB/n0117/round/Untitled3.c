#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stddef.h>

void string_reverse(char* str, int len)
{
    /*USAGE
       char x[]= {'1','2','3'};
       string_reverse(x,3);
       printf("%s",x);*/
    if (len <=0) {return;}
    char* start = str;
    char* end = str+len-1;
    char tmp;
    while(end>start)
    {
        tmp=*start;
        *start=*end;
        *end=tmp;
        start++;
        end--;
    }

}

void row_reverse(char* str)
{
    char* end=str;
    char* start=str;
    while(*end!='\0')
    {
        if(*end=='\n')
        {
            string_reverse(start,end-start);
            start=end+1;
        }
        end++;
    }
    string_reverse(start,end-start);
    string_reverse(str,strlen(str));
}

int main()
{
    char x[]= "abc\n123\n";
    row_reverse(x);
    printf("%s",x);
}
