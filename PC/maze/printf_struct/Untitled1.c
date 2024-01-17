#include <stdio.h>
int main(){
char f[] = "%hhn";
printf(f, (signed char *)f);
}
