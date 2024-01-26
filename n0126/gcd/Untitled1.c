//最大公因數，輾轉相除法
#include <stdio.h>
#include <stdlib.h>

int x(int a , int b){
if(a%b==0){
    return b;
}else{
return x(b,a%b);
}
}

int main(){
int a = 1112;
int b = 695;
printf("%d",x(a,b));
}
