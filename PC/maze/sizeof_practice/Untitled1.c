#include <stdio.h>

int main()
{
    int x[5];
    printf("sizeof(x): %d\nsizeof(x[0]): %d\nlength(x): %d\n\tVVV\n",
           (int) sizeof(x),
           (int) sizeof(x[0]),
           (int) sizeof(x)/(int) sizeof(x[0])
          );

    typedef struct S_y
    {
        int a;
        char b;
    } T_y;
    T_y y[5];
    printf("sizeof(y): %d\nsizeof(y[0]): %d\nlength(y): %d\nsizeof(int): %d\nsizeof(char): %d\n",
           (int) sizeof(y),
           (int) sizeof(y[0]),
           (int) sizeof(y)/(int) sizeof(y[0]),
           (int) sizeof(int),(int) sizeof(char)
          );
}
///問題就是:
///是否只要陣列是以指標呈現，sizeof 就不管用 ... 這個部分去看 ???
