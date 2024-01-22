//今天想依照成員的年紀排序
#include <stdio.h>
#include <stdlib.h>
#include <stddef.h>
#include <stdbool.h>
typedef struct member{
char *name;
unsigned char age;
}member;

bool compareMember(member *e1, member *e2){
return strcmp(e1->name,e2->name)==0?true:false;
}

void displayMember(member *e){
printf("%s\t%d\n",e->name,e->age);
}

int main(){
member m;
m->age=17;
m->name="HSU PEI WAN";
displayMember(m);
}
