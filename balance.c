#include <stdio.h>
#include <string.h>
#define size 100

char stack[size];
int top = -1;

void push(char c) {
    if (top == size - 1) return;
    stack[++top] = c;
}

char pop() {
    if (top == -1) return '\0';
    return stack[top--];
}

int isBalanced(char exp[]) {
    for (int i = 0; exp[i] != '\0'; i++) {
        char ch = exp[i];
        if (ch == '(' || ch == '{' || ch == '[') {
            push(ch);
        }
        else if (ch == ')' || ch == '}' || ch == ']') {
            if (top == -1) return 0; // stack underflow → unbalanced
            char topChar = pop();
            if ((ch == ')' && topChar != '(') ||
                (ch == '}' && topChar != '{') ||
                (ch == ']' && topChar != '[')) {
                return 0; // mismatched pair
            }
        }
    }
    return top == -1; // balanced if stack is empty at end
}

int main() {
    char exp[100];
    printf("Enter expression: ");
    fgets(exp, sizeof(exp), stdin);

    if (isBalanced(exp))
        printf("Balanced\n");
    else
        printf("Not Balanced\n");

    return 0;
}
