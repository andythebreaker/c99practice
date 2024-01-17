#include <stdio.h>
#include <stdbool.h>

#define COUNT_X 200
#define COUNT_Y 50
#define NL printf("\n");
#define PRINT_2D_ARY(ARG_ARY,ARG_X,ARG_Y) for(int DEFINE_I=(ARG_Y); DEFINE_I>=0; --DEFINE_I){for(int DEFINE_J=0; DEFINE_J<(ARG_X); DEFINE_J++){printf("%c",((ARG_ARY)[(DEFINE_J)][(DEFINE_I)])?'O':'.');}NL}


int main()
{
    bool m[COUNT_X][COUNT_Y]= {{false}};
    //fucn_draw_line(m);
    PRINT_2D_ARY(m,COUNT_X,COUNT_Y)
}
