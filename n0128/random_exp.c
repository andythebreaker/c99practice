#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define GROUPNUM 5
int comp(const void *a, const void *b)
{
    return (*((int *)a)) - (*((int *)b));
}
int *gen_rand()
{
    int *tmp = (int *)malloc(sizeof(int) * GROUPNUM);
    srand((unsigned)time(NULL));
    int i = 0;
    while (i < GROUPNUM)
    {
        int x = rand();
        // printf("%d\t",x);
        void *y = bsearch(&x, tmp, i, sizeof(int), &comp);
        // printf("%p\t", y);
        if (y == NULL)
        {
            tmp[i++] = x % 40;
            // printf("%d\t",tmp[0]);
            qsort(tmp, i, sizeof(int), &comp);
        }
    }
    return tmp;
}
int main()
{
    printf("Hello World!\n");
    // srand((unsigned)time(NULL));
    //  printf("%d\t",rand());printf("%d\t",rand());printf("%d\t",rand());printf("%d\t",rand());printf("%d\t",rand());printf("%d\t",rand());printf("%d\t",rand());printf("%d\t",rand());printf("%d\t",rand());printf("%d\t",rand());printf("%d\t",rand());printf("%d\t",rand());printf("%d\t",rand());
    int *tmp = gen_rand();
    printf("\nMY RAND\n");
    for (size_t i = 0; i < GROUPNUM; i++)
    {
        printf("%d\t", tmp[i]);
    }
}