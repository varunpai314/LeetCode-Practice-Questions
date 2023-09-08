#include<stdio.h>
#include<stdbool.h>
#include<string.h>
#define SIZE 100
bool isValid(char s[]) {
    char stk[SIZE + 1];
    int top = -1;

    for (int i = 0; i < strlen(s); i++) {
        char ch = s[i];

        if (ch == '(' || ch == '{' || ch == '[') {
            stk[++top] = ch;
        } else if (ch == ')') {
            if (top == -1 || stk[top] != '(') {
                return false;
            }
            top--;
        } else if (ch == '}') {
            if (top == -1 || stk[top] != '{') {
                return false;
            }
            top--;
        } else if (ch == ']') {
            if (top == -1 || stk[top] != '[') {
                return false;
            }
            top--;
        } else {
            return false;
        }
    }

    return top == -1;
}


int main() {
    char input[SIZE];

    printf("Enter a string containing parentheses, curly braces, and square brackets: ");
    scanf("%s", input);

    if (isValid(input)) {
        printf("The input string is valid.\n");
    } else {
        printf("The input string is not valid.\n");
    }

    return 0;
}