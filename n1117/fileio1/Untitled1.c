
#include <stdio.h>

int main(){
FILE *fp;
char buff[256];
fp=fopen("C:\\Users\\ai\\Documents\\andy\\code\\c99practice\\n1117\\fio_data\\f1.txt","w+");
printf("return of fprint: %d\n",fprintf(fp,"abcxyz"));
printf("return of fputs: %d\n",fputs("123456",fp));
printf("return of fgets:%d; feof is reached: %d\n",fgets(buff,256,fp),);
fclose(fp);
}
