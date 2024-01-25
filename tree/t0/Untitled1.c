
#include <stdio.h>
#include <stdlib.h>
#include <stddef.h>
#include <string.h>
#include <ctype.h>
#define IF_HEIGHT
typedef struct _tree
{
    void *data;
    struct _tree *left;
    struct _tree *right;
} TreeNode;

typedef int (*COMPARE)(void* a,void* b);

typedef struct Member
{
    int height;
    int age;
    char name[];
} Member;

int Compare(void* a,void* b)
{
    printf("---compare(%d,%d)---\n",((Member*)a)->age,((Member*)b)->age);
    #ifdef IF_HEIGHT
    return ((Member*)a)->height - ((Member*)b)->height;
    #else
    return ((Member*)a)->age - ((Member*)b)->age;
    #endif
}

void insertNode(TreeNode **realRoot, COMPARE compare, void* data)
{
    TreeNode *node = (TreeNode*) malloc(sizeof (TreeNode));
    node->data = data;
    node->left = NULL;
    node->right = NULL;

    TreeNode *root = *realRoot;

    if (root == NULL)
    {
        *realRoot = node;
        return;
    }

    while (1)
    {
        if (compare((root)->data, data) > 0)
        {
            if ((root)->left != NULL)
            {
                root = (root)->left;
            }
            else
            {
                (root)->left = node;
                break;
            }
        }
        else
        {
            if ((root)->right != NULL)
            {
                root = (root)->right;
            }
            else
            {
                (root)->right = node;
                break;
            }
        }
    }
}

typedef Member *MEMBER;

MEMBER newMember(char* str)
{
    char* age_ptr = str+70;
    str+=strlen("member name:");
    char name_buff[29];
    memcpy(name_buff,str,28);
    name_buff[28]='\0';
    char* ptr=name_buff;
    while(isspace(*ptr))
    {
        ptr++;
    }
    char* name=ptr;
    ptr=name_buff+strlen(name_buff)-1;
    while(isspace(*ptr))
    {
        ptr--;
    }
    *(++ptr)='\0';
    char age_str[4+1+2+1+2+1];
    memcpy(age_str,age_ptr,4+1+2+1+2);
    age_str[4+1+2+1+2]='\0';
    int tmp_age = atoi(age_str);
    char height_str[4];
    memcpy(height_str,age_ptr+18,3);
    height_str[3]='\0';
    int tmp_height = atoi(height_str);
    MEMBER m = (MEMBER)malloc(sizeof(Member)+(strlen(name)+1)*sizeof(char));
    m->age=tmp_age;
    m->height=tmp_height;
    strcpy(m->name,name);
    return m;
}

typedef void (*DISPLAY)(void*);

void Display(void *data)
{
    printf("===============\n");
    printf("|  Node Data  |\n");
    printf("|    Member   |\n");
    printf("| name:%s\n",((MEMBER)data)->name);
    printf("| age:%d      |\n",((MEMBER)data)->age);
    printf("| height:%d  |\n",((MEMBER)data)->height);
    printf("===============\n");
}

void inOrder(TreeNode *root, DISPLAY display)
{
    if(root!=NULL)
    {
        inOrder(root->left,display);
        display(root->data);
        inOrder(root->right,display);
    }
}

int main()
{
    TreeNode *tree = NULL;
    insertNode(&tree,&Compare,newMember("member name:             TSAI, YA-EN    birthdate: 2000 10 21   age:  23        height: 160"));
    insertNode(&tree,&Compare,newMember("member name:             LIN, JIA-NI    birthdate: 2005  1 16   age:  19        height: 162"));
    insertNode(&tree,&Compare,newMember("member name:              FUJII MAYU    birthdate: 1998 11 30   age:  25        height: 163"));
    insertNode(&tree,&Compare,newMember("member name:                PO, LING    birthdate: 1999  9 13   age:  24        height: 157"));
    insertNode(&tree,&Compare,newMember("member name:          LIN, CHIA-YING    birthdate: 2000 12  4   age:  23        height: 160"));
    insertNode(&tree,&Compare,newMember("member name:           LIU, JIE-MING    birthdate: 1997  4 19   age:  26        height: 165"));
    insertNode(&tree,&Compare,newMember("member name:          TSENG, SHIH-YU    birthdate: 1995  2 12   age:  28        height: 155"));
    insertNode(&tree,&Compare,newMember("member name:           CHEN, SHIH-YA    birthdate: 1995  4 24   age:  28        height: 153"));
    insertNode(&tree,&Compare,newMember("member name:               Abe Maria    birthdate: 1995 11 29   age:  28        height: 168"));
    insertNode(&tree,&Compare,newMember("member name:            HONDA YUZUKA    birthdate: 2006  3 15   age:  17        height: 142"));
    inOrder(tree,&Display);
}
