#include <stdio.h>
int main(){
    int a[2];
    a[0]=48;
    a[1]=50;
    printf("%lld\n%lld\n%lld",(long long)(&(a[0])),(long long)(&(a[1])),(long long)(&(a[0]))-(long long)(&(a[1])));
}