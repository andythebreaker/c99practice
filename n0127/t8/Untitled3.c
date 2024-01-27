#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <stddef.h>
#include <ctype.h>
#include <stdbool.h>
#define OX_schedule "OXXOXXO-OX--O-XOOXXO-X-X-XOO-OXO-OOX-OXOO-OO-XXOO-XXOXOOX-OX-X-XOXXOXOOOX-O--OX-XX--OO-OXXOXOOXO---OOXXXXOO-XXO-OX-O-OXOOOO--OXX-OXXXXO-OX-OOX-OO-X-XXOOX-XO-OXO-OXXOOXX-OXXO-XOO-O-XXOO--OOOXX-OXXO--XO-XXO-O-OOO-OOX-OOOX-XXO-OO-XOXXOXXXO--XXO-O-OXXOXOO---OXXXX-OOOOXO--OXOOXOXX-XX-OO-X-OX-OXXO-XXO-XOO-O-OX-XOXXOO-OOO-XXXOOOX-XXOX-O-OXO--XXOO--OOOXXOXXXOXO---XOXXX--OO-OXX-OX-OO-OX-X-OOOXO-XOXOXOX-OXOXO--XXXOOXOX-XOXOOO---XO--OXXOX-OOXO-OXOOX-OOX-OXXOOXXOOOXXXOO-OOX--O-OXXOX---X-XXOOOXXOXXXOO--X-X-O-O--XXXX-OOOOOOO--XOXX-O-O-XXX-OOOXOOXXX-OOOO-OOO--OXXXO-XX-O-OOXX-XX-OO--OOOXOXO---XXOXX-XOOOXO-XXOX--OOOO-X--XO-XOOOX-O----XOO-XXOO-XOO-XOOXOXO-X--XO--XOX-XXXOOXOX--XOOOOOO-O-XXOO-O-OXO--O---XX--OOXXOXOX-OX-OXOO-OO--XOXXOO-OXOXO-O--O-XOX--O-O-OOX-OX-OO-X--XOOX-OXX--XO-X--OO-XXOO-OO-OO--X-OO-OO--X-OXOX-O-OOX----X-XX-OOO--OX---XOOOO-O--XO--OO-----OXXOX-OOOX--OX-XOOOXXXOOOO---XO-O-OO-X-OXX-OOXOOO---OXOXO-X-OXO-X-OO-X---OXXXOO-OO-OX-O-X-OXXO--XO-OO-OOXO-O-X-X---OOOOOXXXOXXOX-OOO---OX---OX--OO-O-XOXXO--OO---OXOX-OO-O--XOO--XO-XO-XXOOO-XO-XXOOO---X-O-XXOX-O-OO-OXO-OO-XOOX-OO-X-O--O-O-OO-XX-OX-XXX-OO----XOXOOOOOXO--XOXO-OO-OOO-OOXX---XOXXOOOO-XO--X-OX----XOXX-OO-OOOXX-O---O-X--OOOO-OXX-O-XOOX--XOXXO--OOOXXXOO--OOOOX--O-X--OXX--OO-O--XOXOO-O-OOO-XOX-X-O--OXOXOOXXX--OOOO----X-X--XOOX-O--X-XOOOX-OO-OO--O-OXXOXOO-O-X--OX-OXO-XX--OOXOOXX-O-O-XX-O-O-OO-O-O-XOO-OX---O-OXOOX--XXXX-OOO-O--XOO-XOOO--XOXOOOO-XO----OXX-X--OOOXOO-XXOX---O-OO-XOX-O-OOXO-X-O-OO----XOX--O-XXXOOOX-OOO-XOOXO--OX--OXX--OOOX-OXO-OO-O-XXO-O--XO-XOOO-OXXXOOOX-O--O-O--OXO--OX-OXXOO-XO--X----OXOOOXXO-OXX-OOO-X-OOXX--OX-OOOO---X-XOO-OXXOO-OXX---O-OO--XOXOO--O--OXOX--XOOOX-XXO-OX-X---OOXOXXXOO-OXX-O-XOXOO--XOOOOXX-XOXXO----OXOX-O-O-XXOXXOOOXOO---XX-XXOXXO-XOOOO--XOOX-XXXOO-O--OOO-O---X-O-X--OXXOO-O-OXOXOX--OXO-XOOX--OOXO-O-X-O-OXO-OOO--XOO--OXX-XOOOOXX-OO---XOXO-X-XOXO-XOOO-OXO-OX-XO--OX-O-X-OOOXXX--O-X-O-OXO-OXOO-XO---O-OX--OOXXXO-XXOOOOOX-X--XX-OOOO-XO-XXXOO-OO--XOX--OX-X-OO-OO-X-OO-OX-OXO-OOXXO--OXXO-XXOO---O-OXOOX--X-OXOOX--OOOX---OXOOOX-O---OXO-X-OXOXOX-X-O-O-O-XXXO-X-X-OO-OO-OXOOXO-X-XOOOXOO-X--OOX-X--OX-OO-X--X-O-OOXOX--OXOOXXOOO-X-OOOO--XXXOXXXOO-OOOX---X-O--O-XOO-XOO-X-OXOX--OOOO--XOX-OOOOXXXOX-X---O-OOOOX-X---OOO-O-XOXXX---OOXX-OOXO-O-OOXX-O-OX-X-OXXOX-OOOXXO---OO--OO-O-O-OX-OXX-XOOO-X-XOXOO---OX--OXOOOOXXX-OX-OOOO---XXX-O-X-OX-O--XOOX-OXOXOO-OX-O--XXOOO--XOOXOO-X--X-XO-O-O-XOO-X---O-O-OXOOXXOOXXOOOO--X-XOXXO--OOOO-O-XXOOX---OOX--XOXO-OOOXX-X---OO--OXOX-OX--O-O-OOXX-OXO-OOX-XXOXO-X-OXXXOO--XO-X-OO-OOX-OOX-OXO-O-OXOOOX--X--"
//這個是一種假設的數據!
const char schedule_all[]=OX_schedule;
typedef enum stat {yes,no,anyway} stat;

typedef struct DaySchedule
{
    stat className[8];
} DaySchedule;

typedef struct Schedule
{
    DaySchedule D[5];
} Schedule;

char *fastSchedule(Schedule schedule)
{
    char *str2return=(char*)malloc((((8*2+2)*5)+1)*sizeof(char));
    char *tmp = str2return;
    for(int i = 0; i < 5 ; i++)
    {
        for(int j = 0; j < 8 ; j++)
        {
            if(schedule.D[i].className[j]==yes)
            {
                *tmp='O';
                tmp++;
                *tmp=' ';
                tmp++;
            }
            else if (schedule.D[i].className[j]==no)
            {
                *tmp='X';
                tmp++;
                *tmp=' ';
                tmp++;
            }
            else
            {
                *tmp='-';
                tmp++;
                *tmp=' ';
                tmp++;
            }
        }
        *tmp=',';
        tmp++;
        *tmp=' ';
        tmp++;
    }
    *tmp='\0';
    return str2return;
}

typedef struct Member
{
    int height;
    int age;
    Schedule schedule;
    char name[];
} Member;

typedef Member *MEMBER;

void append_schedule_2_MEMBER(MEMBER member, const char *schedule_all_)
{
    //hot fix schedule_all no use
    static char *schedule_all_PTR=(char*)schedule_all;
    for(int i = 0; i < 5 ; i++)
    {
        for(int j = 0; j < 8 ; j++)
        {
            member->schedule.D[i].className[j]=(*schedule_all_PTR=='O')?yes:(*schedule_all_PTR=='X')?no:anyway;
            schedule_all_PTR++;
        }
    }
}

MEMBER newMember(const char* schedule,char* str)
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
    append_schedule_2_MEMBER(m,schedule);
    return m;
}

typedef struct Node
{
    void *data;
    struct Node *next;
} Node;

typedef struct LinkedList
{
    struct Node *Head,*Tail;
} LinkedList;

typedef LinkedList Heap;

void initHeap(Heap* heap)
{
    heap->Head=NULL;
    heap->Tail=NULL;
}

void addHeap(Heap *heap,void *data)
{
    Node *tmp = (Node*) malloc(sizeof(Node));
    tmp->data=data;
    tmp->next=NULL;
    if(heap->Head==NULL)
    {
        tmp->next=NULL;
        heap->Head=tmp;
    }
    else
    {
        heap->Tail->next=tmp;
    }
    heap->Tail=tmp;
}

void *popHeap(Heap *heap)
{
    if(heap->Head==NULL)
    {
        return NULL;
    }
    else
    {
        if(heap->Head==heap->Tail)
        {
            heap->Tail=NULL;
        }
        void *tmp=heap->Head->data;
        Node *tmp2free=heap->Head;
        heap->Head=heap->Head->next;
        free(tmp2free);
        return tmp;
    }
}

Schedule every_one_ok(Heap *heap)
{
    Schedule stuff2return;
    for(int i = 0; i < 5; i++)
    {
        for(int j = 0 ; j <8 ; j++)
        {
            Node *tmp=heap->Head;
            while(tmp!=NULL)
            {
                if(((MEMBER)(tmp->data))->schedule.D[i].className[j]==no)
                {
                    stuff2return.D[i].className[j]=no;
                    break;
                }
                tmp=tmp->next;
            }
        }
    }
    return stuff2return;
}

//TODO
//2. all men able | all men disable;
//3. 幹真的要看書 棋盤/遊戲問題

int main()
{
    Heap heap;
    initHeap(&heap);
    addHeap(&heap,newMember(schedule_all,"member name:             SU, HENG-YU    birthdate: 2010 12 26   age:  13        height: 155"));
    addHeap(&heap,newMember(schedule_all,"member name:        CHANG, SHAO-TONG    birthdate: 2008  2 28   age:  15        height: 164"));
    addHeap(&heap,newMember(schedule_all,"member name:            HONDA YUZUKA    birthdate: 2006  3 15   age:  17        height: 142"));
    addHeap(&heap,newMember(schedule_all,"member name:           HUANG, YU-YAN    birthdate: 2006  6  8   age:  17        height: 154"));
    addHeap(&heap,newMember(schedule_all,"member name:           KAO, YEN-CHEN    birthdate: 2006  7 16   age:  17        height: 155"));
    addHeap(&heap,newMember(schedule_all,"member name:         WONG, MANN-LING    birthdate: 2006 12 23   age:  17        height: 170"));
    addHeap(&heap,newMember(schedule_all,"member name:            HSU, PEI-WAN    birthdate: 2006  1 23   age:  18        height: 151"));
    addHeap(&heap,newMember(schedule_all,"member name:           CHEN, YI-LING    birthdate: 2005 10 19   age:  18        height: 157"));
    addHeap(&heap,newMember(schedule_all,"member name:           CHEN, ZHAO-NI    birthdate: 2005  9  6   age:  18        height: 167"));
    addHeap(&heap,newMember(schedule_all,"member name:            LO, JUI-TING    birthdate: 2004  8  6   age:  19        height: 155"));
    addHeap(&heap,newMember(schedule_all,"member name:            WU, WAN-LING    birthdate: 2004  8 10   age:  19        height: 155"));
    addHeap(&heap,newMember(schedule_all,"member name:             LIN, JIA-NI    birthdate: 2005  1 16   age:  19        height: 162"));
    addHeap(&heap,newMember(schedule_all,"member name:             LI, CAI-JIE    birthdate: 2004  3 15   age:  19        height: 164"));
    addHeap(&heap,newMember(schedule_all,"member name:          CHENG, CHIA-YU    birthdate: 2004  4 28   age:  19        height: 164"));
    addHeap(&heap,newMember(schedule_all,"member name:          CHANG, YU-LING    birthdate: 2003  7 11   age:  20        height: 153"));
    addHeap(&heap,newMember(schedule_all,"member name:           CHOU, CHIA-AN    birthdate: 2003 10  9   age:  20        height: 158"));
    addHeap(&heap,newMember(schedule_all,"member name:         TUNG, ZIH-SYUAN    birthdate: 2003 12  4   age:  20        height: 163"));
    addHeap(&heap,newMember(schedule_all,"member name:         CHEN, YING-ZHEN    birthdate: 2004  1  2   age:  20        height: 164"));
    addHeap(&heap,newMember(schedule_all,"member name:       FAN CHIANG, YU-EN    birthdate: 2003  3 20   age:  20        height: 166"));
    addHeap(&heap,newMember(schedule_all,"member name:                 YI, PIN    birthdate: 2003  4 26   age:  20        height: 166"));
    addHeap(&heap,newMember(schedule_all,"member name:           CHENG, YU-WEI    birthdate: 2003 11 11   age:  20        height: 174"));
    addHeap(&heap,newMember(schedule_all,"member name:           HUANG, YI-LIN    birthdate: 2002  4 24   age:  21        height: 155"));
    addHeap(&heap,newMember(schedule_all,"member name:          LEE, MENG-CHUN    birthdate: 2002  6  4   age:  21        height: 165"));
    addHeap(&heap,newMember(schedule_all,"member name:          MENG, TING-YUN    birthdate: 2002 11 28   age:  21        height: 166"));
    addHeap(&heap,newMember(schedule_all,"member name:            KUO, SHIN-YU    birthdate: 2002 10 11   age:  21        height: 174"));
    addHeap(&heap,newMember(schedule_all,"member name:           WANG, YI-CHIA    birthdate: 2001 11 18   age:  22        height: 158"));
    addHeap(&heap,newMember(schedule_all,"member name:            TSAI, YI-JOU    birthdate: 2001  7 15   age:  22        height: 161"));
    addHeap(&heap,newMember(schedule_all,"member name:              LI, JIA-LI    birthdate: 2001 11  5   age:  22        height: 165"));
    addHeap(&heap,newMember(schedule_all,"member name:          LAU, HIU-CHING    birthdate: 2000  8  2   age:  23        height: 158"));
    addHeap(&heap,newMember(schedule_all,"member name:             TSAI, YA-EN    birthdate: 2000 10 21   age:  23        height: 160"));
    addHeap(&heap,newMember(schedule_all,"member name:          LIN, CHIA-YING    birthdate: 2000 12  4   age:  23        height: 160"));
    addHeap(&heap,newMember(schedule_all,"member name:           CHIU, PIN-HAN    birthdate: 1999 12 24   age:  24        height: 153"));
    addHeap(&heap,newMember(schedule_all,"member name:                PO, LING    birthdate: 1999  9 13   age:  24        height: 157"));
    addHeap(&heap,newMember(schedule_all,"member name:            LIN, TING-LI    birthdate: 1999  6  1   age:  24        height: 161"));
    addHeap(&heap,newMember(schedule_all,"member name:            SIN, TIK-KEI    birthdate: 1999  2 13   age:  24        height: 165"));
    addHeap(&heap,newMember(schedule_all,"member name:           YUAN, TZU-CHU    birthdate: 1999  5  7   age:  24        height: 171"));
    addHeap(&heap,newMember(schedule_all,"member name:            CHIA, I-CHEN    birthdate: 1999  8 18   age:  24        height: 175"));
    addHeap(&heap,newMember(schedule_all,"member name:             WU, CHI-HUI    birthdate: 1998 10 25   age:  25        height: 160"));
    addHeap(&heap,newMember(schedule_all,"member name:              FUJII MAYU    birthdate: 1998 11 30   age:  25        height: 163"));
    addHeap(&heap,newMember(schedule_all,"member name:            ZHOU, JIA-YU    birthdate: 1997 11 19   age:  26        height: 157"));
    addHeap(&heap,newMember(schedule_all,"member name:         WENG, TUNG-HSUN    birthdate: 1997  5 19   age:  26        height: 162"));
    addHeap(&heap,newMember(schedule_all,"member name:           LIU, JIE-MING    birthdate: 1997  4 19   age:  26        height: 165"));
    addHeap(&heap,newMember(schedule_all,"member name:             PAN, TZU-YI    birthdate: 1996  7 28   age:  27        height: 157"));
    addHeap(&heap,newMember(schedule_all,"member name:             MIYATA RUKA    birthdate: 1996  4 22   age:  27        height: 158"));
    addHeap(&heap,newMember(schedule_all,"member name:           CHEN, SHIH-YA    birthdate: 1995  4 24   age:  28        height: 153"));
    addHeap(&heap,newMember(schedule_all,"member name:          TSENG, SHIH-YU    birthdate: 1995  2 12   age:  28        height: 155"));
    addHeap(&heap,newMember(schedule_all,"member name:               Abe Maria    birthdate: 1995 11 29   age:  28        height: 168"));
    char *every_one_ok_str = fastSchedule(every_one_ok(&heap));
    printf("\x1b[33;40m%s\x1b[0m\n",every_one_ok_str);
    free(every_one_ok_str);
    while(heap.Tail!=NULL)
    {
        MEMBER tmp = (MEMBER)(popHeap(&heap));
        char *tmp_str = fastSchedule(tmp->schedule);
        printf("%30s(%2d)%3d:%s\n",tmp->name,tmp->age,tmp->height,tmp_str);
        free(tmp);
        free(tmp_str);
    }
}
