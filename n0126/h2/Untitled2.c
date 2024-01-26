
#include <stdio.h>
int rec=0;
void ho(int n, int a, int b, int c){
    if(n>0){
ho(n-1,b,a,c);
rec++;
printf("[%3d] move %d to %d\n",rec,a,c);
ho(n-1,a,c,b);
    }
}

int main(){
ho(6,1,2,3);
}
