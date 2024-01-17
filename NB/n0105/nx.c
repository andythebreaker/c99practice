#include <stdio.h>
#include <string.h>
int main(int argc, char** argv){
	char x[3];
	char* y=argv[1];
	while (*y!='\0'){
		printf("%c",*y++);
	}
	//strcpy(x,argv[1]);
	//printf("%s",x);
}
