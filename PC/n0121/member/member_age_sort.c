
//今天想依照成員的年紀排序
#include <stdio.h>
#include <stdlib.h>
#include <stddef.h>
#include <stdbool.h>
#include <string.h>

//#include "sq.h"//quicksort

//省略l
#define NEW_MEMBER(NICKNAME,NAME,AGE) member *NICKNAME = (member*) malloc(sizeof(member)+strlen(NAME)); NICKNAME->age=AGE; strcpy(NICKNAME->name,NAME);
#define ADD_NEW_MEMBER_HEAD(NICKNAME,NAME,AGE) NEW_MEMBER(NICKNAME,NAME,AGE) addHead(l,NICKNAME);
#define ADD_NEW_MEMBER_TAIL(NICKNAME,NAME,AGE) NEW_MEMBER(NICKNAME,NAME,AGE) addTail(l,NICKNAME);
#define DEL_MEMBER(MEMBER_OBJ_LOCATION) node *tmp_MEMBER_OBJ_LOCATION = getNode(l,(compare)compareMember,MEMBER_OBJ_LOCATION); free(MEMBER_OBJ_LOCATION); delete_l(l,tmp_MEMBER_OBJ_LOCATION);

typedef struct member
{
    unsigned char age;
    char name[];
} member;

bool compareMember(member *e1, member *e2)
{
    return strcmp(e1->name,e2->name)==0?true:false;
}

void displayMember(member *e)
{
    printf("%s\t%d\n",e->name,e->age);
}

typedef void (*display)(void*);
typedef int (*compare)(void*,void*);

//單向串列
typedef struct node
{
    void *data;
    struct node *next;
} node;

typedef struct linkedlist
{
    node *head;
    node *tail;
    node *current;
} linkedlist;

void initializeList(linkedlist*);
void addHead(linkedlist*,void*);
void addTail(linkedlist*,void*);
void delete_l(linkedlist*,node*);
node *getNode(linkedlist*,compare,void*);
void displayLinkedList(linkedlist*,display);

//linkedlist *quicksort(linkedlist *l)
//{
//    node *ptr = l->head;
//    unsigned char baseline = ((member*)(ptr->data))->age;//?
//    ptr=ptr->next;
//    linkedlist *small_input=malloc(sizeof(linkedlist));
//    linkedlist *big_input=malloc(sizeof(linkedlist));
//    initializeList(small_input);
//    initializeList(big_input);
//    while(ptr!=NULL)
//    {
//        if(((member*)ptr->data)->age>baseline)
//        {
//            addHead(big_input,ptr->data);
//        }
//        else
//        {
//            addHead(small_input,ptr->data);
//        }
//        //next...
//        ptr=ptr->next;
//    }
//    linkedlist small_output_;
//    linkedlist big_output_;
//    linkedlist *small_output=&small_output_;
//    linkedlist *big_output=&big_output_;
//    if(small_input->head!=small_input->tail)small_output=quicksort(small_input);
//    if(big_input->head!=big_input->tail)big_output=quicksort(big_input);
//
//    small_output->tail->next=(big_input->head==big_input->tail)?big_output->head(big_output->head);
//
//    node *free_ptr = small_input->head;
//    while(free_ptr!=NULL)
//    {
//        node *tmp_free_ptr = free_ptr->next;
//        free(free_ptr);
//        free_ptr=tmp_free_ptr;
//    }
//    free_ptr = big_input->head;
//    while(free_ptr!=NULL)
//    {
//        node *tmp_free_ptr = free_ptr->next;
//        free(free_ptr);
//        free_ptr=tmp_free_ptr;
//    }
//
//
//        return small_output;
//
//}

void Partition(int a[],int low,int high){
int pivot=A[low];
while(low<high){
    while(low<high&&A[high]>=pivot){
        --high;
    }
    A[low]=A[high];
    while(low<high&&A[low]<=pivot){
        ++low;
    }
    A[high]=A[low];
    A[low]=pivot;
    return low;
}
}
void QuickSort(int A[],int low,int high){
if(low<high){
    int pivot=Partition(A,low,high);
    QuickSort(A,low,pivot-1);
    QuickSort(A,pivot+1,high);
}
}

int main()
{
    linkedlist l_;
    linkedlist *l = &l_;
    member *Melody = (member*)malloc(sizeof(member)+strlen("WONG MANN LING"));
    strcpy(Melody->name,"WONG MANN LING");
    Melody->age=17;
    NEW_MEMBER(Nini,"CHEN ZHAO NI",17)
    NEW_MEMBER(YI_PIN,"YI PIN",20)
    NEW_MEMBER(Myu,"MENG TING YUN",21)
    NEW_MEMBER(Hitomi,"CHANG SHAO TONG",15)

    initializeList(l);

    ADD_NEW_MEMBER_TAIL(CHEN_YING_ZHEN,"CHEN YING ZHEN",20)

    addHead(l,Melody);
    addHead(l,Nini);
    addHead(l,YI_PIN);
    addHead(l,Myu);
    addHead(l,Hitomi);

    //TO REMOVE
    ADD_NEW_MEMBER_TAIL(LIN_JIA_NI,"LIN, JIA-NI",19)

    ADD_NEW_MEMBER_HEAD(YILIN,"HUANG YI LIN",21)
    ADD_NEW_MEMBER_HEAD(WU_CHI_HUI,"WU CHI HUI",25)
    ADD_NEW_MEMBER_HEAD(YUAN_TZU_CHU,"YUAN TZU CHU",24)
    ADD_NEW_MEMBER_HEAD(WENG_TUNG_HSUN,"WENG TUNG HSUN",26)
    ADD_NEW_MEMBER_HEAD(KUO_HSING_YU,"KUO HSING YU",21)
    ADD_NEW_MEMBER_HEAD(LIN_YU_HSIN,"LIN YU HSIN",22)
    ADD_NEW_MEMBER_HEAD(Mina,"PAN TZU YI",27)
    ADD_NEW_MEMBER_HEAD(Koharu,"LAU HIU CHING",23)
    ADD_NEW_MEMBER_TAIL(Yusi,"HSU PEI WAN",17)
    ADD_NEW_MEMBER_TAIL(Nana,"CHEN YI LING",18);

    displayLinkedList(l,(display)displayMember);
    printf("\n\t\t<<del>>\t...\n");
    DEL_MEMBER(LIN_JIA_NI)
    displayLinkedList(l,(display)displayMember);
//    printf("\n\t\t<<quick sort>>\t...\n");
//    displayLinkedList(quicksort(l),(display)displayMember);
}

void initializeList(linkedlist *list)
{
    list->head=NULL;
    list->tail=NULL;
    list->current=NULL;
}

void addHead(linkedlist *list,void *data)
{
    node *n=(node*)malloc(sizeof(node));
    n->data=data;
    if (list->head==NULL)
    {
        list->tail=n;
        n->next=NULL;
    }
    else
    {
        n->next=list->head;
    }
    list->head=n;
}

void displayLinkedList(linkedlist *list,display d)
{
    printf("\nLinkedList\n");
    node *current=list->head;
    while(current!=NULL)
    {
        d(current->data);
        current=current->next;
    }
}

void addTail(linkedlist *list,void *data)
{
    node *n=(node*)malloc(sizeof(node));
    n->data=data;
    n->next=NULL;
    if(list->head==NULL)
    {
        list->head=n;
    }
    else
    {
        list->tail->next=n;
    }
    list->tail=n;
}

node *getNode(linkedlist *list,compare c,void *data)
{
    node *n=list->head;
    while(n!=NULL)
    {
        if(c(n->data,data)==true)
        {
            return n;
        }
        n=n->next;
    }
    return NULL;
}

void delete_l(linkedlist *list,node *n)
{
    if(n==list->head)
    {
        if(list->head->next==NULL)
        {
            list->head=list->tail=NULL;
        }
        else
        {
            list->head=list->head->next;
        }
    }
    else
    {
        node *tmp=list->head;
        while(tmp!=NULL&&tmp->next!=n)
        {
            tmp=tmp->next;
        }
        if(tmp!=NULL)
        {
            tmp->next=n->next;
        }
        free(n);
    }
}
