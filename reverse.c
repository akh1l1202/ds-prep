#include <stdio.h>
#define size 100

int top = -1;

char stack[size];

void push(char c) {
    if (top==size-1) {
        return;
    }
    top++;
    stack[top] = c;
}

void pop() {
    if (top==-1) {
        return;
    }
    printf("%c",stack[top]);
    top--;
}

int main() {
    char s[100];
    printf("Enter string to be reversed: ");
    fgets(s,sizeof(s),stdin);
    for (int i=0; s[i]!='\0';i++) {
        push(s[i]);
    }
    printf("Your reversed string is: ");
    for (int i=top;i>=0;i--) {
        pop();
    }
}
