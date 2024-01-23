#include <stdio.h>
#include <string.h>
int main(){
    char x[]="abc";
    printf("sizeof(x)/sizeof(char)=%d/%d=%d=strlen(x)=%d",(int)sizeof(x),(int)sizeof(char),(int)(sizeof(x)/sizeof(char)),(int)strlen(x));
}