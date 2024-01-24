
#include <stdio.h>
#include <stdlib.h>
#include <stddef.h>

typedef struct _tree{
void *data;
struct _tree *left;
struct _tree *right;
}TreeNode;

typedef int (*COMPARE)(void* a,void* b);

typedef struct Member{
int age;
char name[];
}Member;

int Compare(void* a,void* b){
return ((Member*)a)->age - ((Member*)b)->age;
}

/*void insertNode(TreeNode **realRoot,Compare compare, void* data){
TreeNode *node = (TreeNode*)malloc(sizeof(TreeNode));
node->data=data;
node->left=NULL;
node->right=NULL;
TreeNode *root=*realRoot;
if(root==NULL){
    *realRoot=node;
    return;
}
while(1){
    if(compare(root->data))
}
}*/

void insertNode(TreeNode **realRoot, COMPARE compare, void* data) {
    TreeNode *node = (TreeNode*) malloc(sizeof (TreeNode));
    node->data = data;
    node->left = NULL;
    node->right = NULL;

    TreeNode *root = *realRoot;

    if (root == NULL) {
        *realRoot = node;
        return;
    }

    while (1) {
        if (compare((root)->data, data) > 0) {
            if ((root)->left != NULL) {
                root = (root)->left;
            } else {
                (root)->left = node;
                break;
            }
        } else {
            if ((root)->right != NULL) {
                root = (root)->right;
            } else {
                (root)->right = node;
                break;
            }
        }
    }
}


int main(){
TreeNode *tree = NULL;
Member
insertNode(&tree,&Compare,)
}
