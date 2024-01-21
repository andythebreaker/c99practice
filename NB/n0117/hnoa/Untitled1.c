#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stddef.h>
#define DIR_file "C:\\Users\\bear\\Desktop\\ntueecs\\n0117\\file"
#define stack_MAX 3
#define LENGTH_stick 1+(2*(stack_MAX+1))*2
#define HEIGHT_stick (stack_MAX+1)*2
#define LENGTH_margin 4
/*typedef struct S_ddll_node
{
    int key;
    struct S_ddll_node;
} T_ddll_node;*/

void p_upsidedown(char* Sin)
{
    char* tmp=(char*) malloc(sizeof(char)*1);
    *tmp='\0';
    for(int i = strlen(Sin); i >= 0; i--)
    {
        if(i==strlen(Sin)&&Sin[i]!='\0')
        {
            printf("ERROR! string not end w/ NULL");
        }
        else
        {
            if(Sin[i]!='\n')
            {
                char* re_tmp=(char*) realloc(tmp,sizeof(char)*(strlen(tmp)+2));
                if(!re_tmp) printf("realloc failed! \n");
                tmp=re_tmp;
                tmp[strlen(tmp)]=Sin[i];
                tmp[strlen(tmp)+1]='\0';
            }else{
            printf("%s",tmp);
            }
        }
    }
}

int main(void)
{
    char* x = "abc\0";
    p_upsidedown(x);
}
