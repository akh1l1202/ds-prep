#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
#define size 100

int top = -1;
int index = -1;

char stack[size];
char reverse[size];

void push(char c) {
    if (top==size-1) {
        return;
    }
    top++;
    stack[top] = c;
}


void push_to_reverse() {
    if (top==-1) {
        return;
    }
    index++;
    reverse[index] = stack[top];
    top--;
}

int main() {
    char s[100];
    printf("Enter string: ");
    fgets(s,sizeof(s),stdin);
    for (int i=0; s[i]!='\0';i++) {
        if (s[i]==' ') {
            continue;
        }
        else if (s[i]=='\n') {
            continue;
        }
        push(tolower(s[i]));
    }
    reverse[index+1] = '\0'; // pushed the string s to stack
    for (int i=top;i>=0;i--) {
        push_to_reverse();
    } //reversed
    for (int i=0;reverse[i]!='\0';i++) {
        printf("%c",reverse[i]);
    }
    if (strcmp(stack,reverse)) {
        printf("\nIt isnt a palindrome");
    }
    else {
        printf("\nIt is a palindrome");
    }
}

