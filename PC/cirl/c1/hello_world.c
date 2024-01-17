#include <stdbool.h>
#include <stdio.h>

#define width 200
#define height 50
#define NL printf("\n");
#define safeIDX(o) if((o)<0)return 48;

typedef struct struct_x
{
    int o_min;
    int o_max;
} type_x;

typedef struct struct_y
{
    int o_min;
    int o_max;
} type_y;

static type_x x;
static type_y y;

typedef struct struct_coordinate
{
    int cx;
    int cy;
} coord;

coord mirror(coord inp, int y_pos_shift){
/*
+-     +  +-      +
| 1 0  |  | inp.x |
| 0 -1 |  | inp.y |
+-     +  +-      +

oupx=inpx*1
oupy=inpy*-1
*/
int tmp_y=inp.cy-y_pos_shift;
coord oup;
oup.cy=tmp_y*-1;
oup.cx=inp.cx*1;
oup.cy+=y_pos_shift;
return oup;
}

int main()
{
    x.o_min=0;
    y.o_min=0;
    x.o_max=width;
    y.o_max=height;
    bool m[height][width] = {{false}};
    //y=x for x from x.min to x.max
    for(size_t i = x.o_min ; i < x.o_max ; i++)
    {
        if(i>=y.o_max)break;
        int tmp_y = i;//this is the function
        coord tmp_i;
        tmp_i.cx=i;
        tmp_i.cy=tmp_y;
        tmp_i=mirror(tmp_i,50);
        m[tmp_i.cy][tmp_i.cx]=true;
    }
    for(size_t i = 0 ; i < height ; i++)
    {
        //O--->O--->O
        //|
        //v

        for(size_t j = 0 ; j < width ; j++)
        {
            safeIDX(i)
            safeIDX(j)
            printf("%d",m[i][j]);
        }
        NL
    }
}
