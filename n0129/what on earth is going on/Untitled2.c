#define DEBUGint(X) stderr("[DEBUG@%s:%d]: %s=%d\n",__func__,__LINE__,#X,X);
#include <stdio.h>
int main(){
    int y = 48;
DEBUGint(y);
}
