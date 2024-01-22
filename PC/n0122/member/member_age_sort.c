
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

//佇列queue(fifo)
typedef linkedlist Queue;
typedef Queue *PTR_queue;
void initializeQueue(Queue*);
void enqueue(Queue*, void*);
void *dequeue(Queue*);

void initializeList(linkedlist*);
void addHead(linkedlist*,void*);
void addTail(linkedlist*,void*);
void delete_l(linkedlist*,node*);
node *getNode(linkedlist*,compare,void*);
void displayLinkedList(linkedlist*,display);

int Partition(int A[],int low,int high)
{
    int pivot=A[low];
    while(low<high)
    {
        while(low<high&&A[high]>=pivot)
        {
            --high;
        }
        A[low]=A[high];
        while(low<high&&A[low]<=pivot)
        {
            ++low;
        }
        A[high]=A[low];
    }
    A[low]=pivot;
    return low;
}
void QuickSort(int A[],int low,int high)
{
    if(low<high)
    {
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
//TODO data
    ADD_NEW_MEMBER_HEAD(WU_CHI_HUI,"WU CHI HUI",25)
    ADD_NEW_MEMBER_HEAD(YUAN_TZU_CHU,"YUAN TZU CHU",24)
    ADD_NEW_MEMBER_HEAD(WENG_TUNG_HSUN,"WENG TUNG HSUN",26)
//TODO data
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

    printf("\n\n===== part of queue =====\n");

    printf("I would like to add... to queue (aka from head):\n");
    //佇列
    Queue queue_;
    PTR_queue q = &queue_;
    initializeQueue(q);
    enqueue(q,WU_CHI_HUI);
    enqueue(q,YUAN_TZU_CHU);
    enqueue(q,WENG_TUNG_HSUN);
    printf("then... I would like to pop... from queue (aka from tail):\n");
    member *tmp_member_after_dequeue = (member*) dequeue(q);
    printf("member info:\tname:%s\tage:%3d",tmp_member_after_dequeue->name,tmp_member_after_dequeue->age);
    free(tmp_member_after_dequeue);
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


void initializeQueue(Queue *queue_)
{
    initializeList(queue_);
}

void enqueue(Queue *queue_, void *n)
{
    addHead(queue_,n);
}

void *dequeue(Queue *queue_) //pop
{
//!他居然是回傳void指標
    node *tmp = queue_->head;
    void *data;
    if(queue_->head==NULL)
    {
        data = NULL;
    }
    else if (queue_->head==queue_->tail)
    {
        queue_->head=queue_->tail=NULL;
        data=tmp->data;
        free(tmp);
    }
    else
    {
        while(tmp->next!=queue_->tail)
        {
            tmp=tmp->next;
        }
        queue_->tail=tmp;
        tmp=tmp->next;
        queue_->tail->next=NULL;
        data=tmp->data;
        free(tmp);
    }
    return data;
}
