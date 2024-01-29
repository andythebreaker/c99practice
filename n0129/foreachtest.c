#include <stdio.h>

#define foreach(t,x,stuff) for(t *z = (t[]){z,(t)0} ; *z ; z++){stuff}

int main(){
int a[] = {1,2,3,4,5};
foreach(int, a ,printf("%d,",*z);)

}