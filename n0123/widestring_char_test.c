#include <stdio.h>
#include <stddef.h>
#include <stdlib.h>
#include <wchar.h>
#include <string.h>
#include <locale.h>
int main(){
setlocale(LC_ALL,"");
system("chcp 65001");
wchar_t x[] = L"繁體中文測試";
printf("%ls\n",x);
wchar_t *y=(wchar_t*)malloc(sizeof(wchar_t)*3);
y[0]=L'甲';
y[1]=L'乙';
y[2]=L'\0';
printf("%ls\n",y);
}
