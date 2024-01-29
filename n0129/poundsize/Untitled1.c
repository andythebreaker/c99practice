#define x(y) int this_is_a_var_name ## y =48;
#include <stdio.h>
int main(){
    x(z)
printf("%d",this_is_a_var_namez);
}
