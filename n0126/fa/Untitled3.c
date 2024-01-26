
#include <stdio.h>
#include <stdlib.h>
int f(int l, int idx){
if(idx==0||idx==l-1){return 1;}else{
   return f(l-1,idx-1)+f(l-1,idx);
}
}

int main(){
int L = 9;
for(int i = 0 ; i< L ;i++){
printf("%4d",f(L, i));
}
}
