/*******************************************************************/
/*                                                                 */
/*     filename : KMeans.c                                         */
/*     author   : edison.shih/edisonx                              */
/*     compiler : Visual C++ 2008                                  */
/*     date     : 2010.03.07                                       */
/*                                                                 */
/*******************************************************************/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

// ------------------------------------
// param define
#define DCNT     100 /* 資料個數   */
#define DIM      3   /* 資料維度   */
#define K        5   /* 叢聚個數   */
#define MAX_ITER 20  /* 最大迭代   */
#define MIN_PT   0   /* 最小變動點 */
#define LOW      20  /* 資料下限   */
#define UP       300 /* 資料上限   */

// ------------------------------------
// variable
double data[DCNT][DIM]; /* 原始資料   */
double cent[DCNT][DIM]; /* 重心       */
double dis_k[K][DIM];   /* 叢聚距離   */
int table[DCNT];        /* 資料所屬叢聚*/
int cent_c[K];          /* 該叢聚資料數*/

// ------------------------------------
// function declare
double cal_dis(double *x, double *y, int dim);
void   get_data();               // 取得資料
void   kmeans_init();            // 演算法初始化
double update_table(int* ch_pt); // 更新table
void   update_cent();            // 更新重心位置
void   print_cent();             // 顯示重心位置
// ------------------------------------
// main function
int main()
{
     int     ch_pt;         /* 紀錄變動之點 */
     int     iter=0;        /* 迭代計數器   */
     double sse1;           /* 上一迭代之sse */
     double sse2;           /* 此次迭代之sse */

     srand((unsigned)time(NULL));    
     get_data();                      /* step 0 - 取得資料            */
     kmeans_init();                   /* step 1 - 初始化,隨機取得重心 */
     sse2 = update_table(&ch_pt);     /* step 2 - 更新一次對應表      */
     do{
           sse1 = sse2, ++iter;
           update_cent();             /* step 3 - 更新重心            */
           sse2=update_table(&ch_pt); /* step 4 - 更新對應表          */
     }while(iter<MAX_ITER && sse1!=sse2 && ch_pt>MIN_PT); // 收斂條件

    print_cent(); // 顯示最後重心位置
    printf("sse   = %.2lf\n", sse2);
    printf("ch_pt = %d\n", ch_pt);
    printf("iter = %d\n", iter);
    return 0;
}

// ------------------------------------
// 計算二點距離
double cal_dis(double *x, double *y, int dim)
{
     int i;
     double t, sum=0.0;
     for(i=0; i<dim; ++i)
           t=x[i]-y[i], sum+=t*t;
     return sum;
}

// ------------------------------------
// 取得資料，此處以隨機給
void get_data()
{
     int i, j;
     for(i=0; i<DCNT; ++i)
           for(j=0; j<DIM; ++j)
                data[i][j] = \
                LOW + (double)rand()*(UP-LOW) / RAND_MAX;
}
// ------------------------------------
// 演算化初始化
void   kmeans_init()
{
     int i, j, k, rnd;
     int pick[K];
     // 隨機找K 個不同資料點
     for(k=0; k<K; ++k){
           rnd = rand() % DCNT; // 隨機取一筆
           for(i=0; i<k && pick[i]!=rnd; ++i);
           if(i==k) pick[k]=rnd; // 沒重覆
           else --k; // 有重覆, 再找一次
     }
     // 將K 個資料點內容複制到重心cent
     for(k=0; k<K; ++k)
           for(j=0; j<DIM; ++j)
                cent[k][j] = data[pick[k]][j];
}

// ------------------------------------
// 更新table, 傳回sse, 存入點之變動數
double update_table(int* ch_pt)
{
     int i, j, k, min_k;
     double dis, min_dis, t_sse=0.0;

     *ch_pt=0;                          // 變動點數設0
     memset(cent_c, 0, sizeof(cent_c)); // 各叢聚資料數清0
     memset(dis_k, 0, sizeof(dis_k));   // 各叢聚距離和清0

     for(i=0; i<DCNT; ++i){
           // 尋找所屬重心
           min_dis = cal_dis(data[i], cent[0], DIM);
           min_k   = 0;
           for(k=1;k<K; ++k){
                dis = cal_dis(data[i], cent[k], DIM);
                if(dis < min_dis)
                     min_dis=dis, min_k = k;
           }
           *ch_pt+=(table[i]!=min_k); // 更新變動點數
           table[i] = min_k;          // 更新所屬重心
           ++cent_c[min_k];           // 累計重心資料數        
           t_sse += min_dis;          // 累計總重心距離
           for(j=0; j<DIM; ++j)       // 更新各叢聚總距離
                dis_k[min_k][j]+=data[i][j];        
     }
     return t_sse;
}

// ------------------------------------
// 更新重心位置
void update_cent()
{
     int k, j;
     for(k=0; k<K; ++k)
           for(j=0; j<DIM; ++j)
                cent[k][j]=dis_k[k][j]/cent_c[k];
}

// ------------------------------------
// 顯示重心位置
void   print_cent()
{
     int j, k;
     for(k=0; k<K; ++k) {
           for(j=0; j<DIM; ++j)
                printf("%6.2lf ", cent[k][j]);
           putchar('\n');
     }
}