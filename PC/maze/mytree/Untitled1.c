//andy the tree
#include <stdio.h>
#include <stdlib.h>
#define add(KEY) tree
typedef struct S_node{
int key;
struct S_node *L;
struct S_node *R;
//���ΨS��build in fucn ���覡
}T_node;
typedef struct S_tree{
T_node* PTR_head,PTR_toe;
int length;
T_node node[];
}T_tree;

int main(){
//declear
T_tree tree;
//init
tree.length=0;
tree.node=(T_node*)malloc(sizeof(T_node));//��malloc�ظ��[]��(�bMAIN��)�t��?
tree.node[0].key=-1;
tree.node[0].L=NULL;
tree.node[0].R=NULL;
tree.PTR_head=tree.node;
tree.PTR_toe=tree.node;
}
