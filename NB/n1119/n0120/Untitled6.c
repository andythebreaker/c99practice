//stdstrtest
#include <stdio.h>
#include <string.h>
#include "Untitled5.h"
void stdstrtest()
{
char s1[]="chu.pin.han.is.beauty";
char s2[]="wang.yee.ja.are.cute";
printf("\t\ts1= '%s', s2= '%s'\n==========\n",s1,s2);
int x = strxfrm(s1,s2,5);
printf("location will be the same:\n\t\ts1= '%s', s2= '%s'; return: %d\n==========\n",strupr(s1),s2,x);
}
