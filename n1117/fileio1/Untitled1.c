
#include <stdio.h>

int main(){
FILE *fp;
fp=fopen("C:\\Users\\ai\\Documents\\andy\\code\\c99practice\\n1117\\fio_data\\f1.txt","w+");
fprintf(fp,"abcxyz");
//fputs
fclose(fp);
}
