//tree2
#include <stdio.h>
///problem1 �ҥH�ƭn���n��@�W���k?�A��linked list?�A�ڥ���ary����k�F���F�A�W���O�d�bstruct ����[]
typedef struct o{
int x;
struct o y[];
}o;
typedef o *o_pt;
int main(void){
//o_pt a = (o_pt) malloc()
printf("%d",sizeof(o));
}
