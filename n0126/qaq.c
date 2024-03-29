#include <stdio.h>
#include <math.h>
#include <stdbool.h>
#include <string.h>
#define EIGHT 4
#define NL printf("\n");
#define PRINTq                                        \
    printf("\x1b[30;45m");                            \
    for (int MACRO_I = 0; MACRO_I < EIGHT; MACRO_I++) \
    {                                                 \
        printf("%2d,", queen[MACRO_I]);               \
    }                                                 \
    printf("\x1b[0m");
#define PRINTQ PRINTq NL
#define big_parantheses(stuff) \
    printf("\x1b[32;40m{");    \
    stuff printf("\x1b[32;40m}");NL
int queen[EIGHT];
int number = 0;
int print_table()
{
    int x = 0, y = 0;
    number++;
    printf("\n");
    printf("No.%d\n", number);
    for (x = 0; x < EIGHT; x++)
    {
        for (y = 0; y < EIGHT; y++)
        {
            if (queen[y] == x)
            {
                printf("Q");
            }
            else
            {
                printf(".");
            }
        }
        printf("\n");
    }
    return 0;
}

bool attack(int row, int col);

#define NOT_PRINT_DECIDE_POSITION(stuff) if(false){stuff}

void decide_position(int value)
{
    NOT_PRINT_DECIDE_POSITION(printf("\x1b[30;43mdecide_position(%d)->\n\x1b[0m", value);)
    int i = 0;
    while (i < EIGHT)
    {
        NOT_PRINT_DECIDE_POSITION(printf("\x1b[37;41m<%d>\x1b[0m", i);)
        if (attack(i, value) != true)
        {
            queen[value] = i;
            NOT_PRINT_DECIDE_POSITION(PRINTQ)
            if (value == EIGHT - 1)
            {
                print_table();
            }
            else
            {
                decide_position(value + 1);
            }
        }
        i++;
    }
    NOT_PRINT_DECIDE_POSITION(printf("\x1b[30;42m<-decide_position(%d)\n\x1b[0m", value);)
}

int main()
{
    queen[0]=3;queen[1]=0;queen[2]=1;queen[3]=2;
    //證實他初值不管如何都會對
    //PRINTQ
    decide_position(0);
    printf("Final No.%d\n", number);
    return 0;
}

#define ATTACK_WHILE(stuff) if(false){stuff}

bool attack(int row, int col)
{
    int i = 0;
    bool atk = false;
    int offset_row = 0, offset_col = 0;
    ATTACK_WHILE(printf("\n==============vvv==============\n");)
    while (atk != 1 && i < col)
    {
        offset_col = abs(i - col);
        offset_row = abs(queen[i] - row);
        ATTACK_WHILE(printf("i=%d,queen[%d]=%d,row=%d;offset_col=|%d-%d|=%d,offset_row=|%d-%d|=%d", i, i, queen[i],row,i,col,offset_col,queen[i],row,offset_row);)
        if (queen[i] == row || offset_col == offset_row)
        {
            atk = true;
            ATTACK_WHILE(printf("ATK");)
        }
        i++;
        ATTACK_WHILE(NL)
    }
    ATTACK_WHILE(printf("\n==============^^^==============\n");)
    big_parantheses(PRINTq printf("[(%2d)(%2d),%s]", row,col,atk ? "true" : "false");) 
    return atk;
}