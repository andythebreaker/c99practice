#include <stdio.h>
#include <string.h>
#include <stdbool.h>
typedef struct struct_wall
{
    /*
    ....N
    W.......E
    ....S
    */
    bool n,e,w,s;
} type_wall;

typedef struct struct_cell
{
    int i,j;
    type_wall wall;
    bool o;
} type_cell;

void json(type_cell cell)
{
    printf("{\"i\":%d,\"j\":%d,\"o\":%s,\"wall\":{\"n\":%s,\"e\":%s,\"w\":%s,\"s\":%s}}",
           cell.i,
           cell.j,
           (cell.o)?"true":"false",
           (cell.wall.n)?"true":"false",
           (cell.wall.e)?"true":"false",
           (cell.wall.w)?"true":"false",
           (cell.wall.s)?"true":"false");
}

int main(void)
{
    type_cell cell;
    cell.i=0;
    cell.j=1;
    cell.o=true;
    cell.wall.n=false;
    cell.wall.e=true;
    cell.wall.w=false;
    cell.wall.s=true;
    json(cell);
}
