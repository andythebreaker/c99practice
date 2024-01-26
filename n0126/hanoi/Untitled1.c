#include <stdio.h>
#include <stdlib.h>
#define LV 3

typedef struct Plate
{
    int data;
    struct Plate *up;
} Plate;

typedef struct Rod
{
    Plate *bottom;
    Plate *top;
} Rod;

void AddPlate(Rod *rod, Plate *plate)
{
    if(rod->top!=NULL&&rod->top->data<plate->data)
    {
        printf("illegal");
        exit(87);
    }
    else
    {
        if(rod->bottom!=NULL)
        {
            rod->top->up=plate;
            rod->top=plate;
        }
        else
        {
            rod->top=plate;
            rod->bottom=plate;
        }
    }
}

Plate *initPlate(int plateNUM)
{
    Plate *plate = (Plate*)malloc(sizeof(Plate));
    plate->data=plateNUM;
    plate->up=NULL;
    return plate;
}

void init(Rod *hanoi)
{
    hanoi[1].bottom=NULL;
    hanoi[2].bottom=NULL;
    hanoi[1].top=NULL;
    hanoi[0].bottom=NULL;
    hanoi[0].top=NULL;
    hanoi[2].top=NULL;
    for(int i =LV ; i > 0 ; i--)
    {
        AddPlate(&(hanoi[0]),initPlate(i));
    }
}

void showRod(Rod *rod)
{
    Plate *pt=rod->bottom;
    while(pt!=NULL)
    {
        printf("%3d,",pt->data);
        pt=pt->up;
    }
    printf(";");
}

void showBoard(Rod *hanoi)
{
    showRod(&(hanoi[0]));
    showRod(&(hanoi[1]));
    showRod(&(hanoi[2]));
}

int main()
{
    Rod hanoi[3];
    init(hanoi);
    showBoard(hanoi);
}
