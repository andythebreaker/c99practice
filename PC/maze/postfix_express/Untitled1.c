#include <stdio.h>
#include <stdlib.h>

#define MAX 80

void inToPostfix(char*, char*); // ��������
int priority(char); // �B��l�u���v

int main(void) {
    char infix[MAX] = {'\0'};
    char postfix[MAX]= {'\0'};

    printf("���ǹB�⦡�G");
    scanf("%s", infix);
    inToPostfix(infix, postfix);

    int i;
    for(i = 0; postfix[i] != '\0'; i++) {
        printf("%c", postfix[i]);
    }

    return 0;
}
//(a+b)*(c+d)
void inToPostfix(char* infix, char* postfix) {
    char stack[MAX] = {'\0'};
    int i, j, top;
    for(i = 0, j = 0, top = 0; infix[i] != '\0'; i++)
        switch(infix[i]) {
        case '(':              // �B��l���|
            stack[++top] = infix[i];
            break;
        case '+': case '-': case '*': case '/':
            while(priority(stack[top]) >= priority(infix[i])) {
                postfix[j++] = stack[top--];
            }
            stack[++top] = infix[i]; // �s�J���|
            break;
        case ')':
            while(stack[top] != '(') { // �J ) ��X�� (
                postfix[j++] = stack[top--];
            }
            top--;  // ����X (
            break;
        default:  // �B�⤸������X
            postfix[j++] = infix[i];
    }
    while(top > 0) {
        postfix[j++] = stack[top--];
    }
}

int priority(char op) {
    switch(op) {
        case '+': case '-': return 1;
        case '*': case '/': return 2;
        default:            return 0;
    }
}

