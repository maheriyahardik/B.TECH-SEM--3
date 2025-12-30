#include <stdio.h>
#include <stdlib.h>

int top = 0;

int f(char c) {
    if (c == '+' || c == '-') return 1;
    else if (c == '*' || c == '/') return 2;
    else if (c == '#') return 0;
    else return 3;
}

int rankVal(char c) {
    if (c == '+' || c == '-' || c == '*' || c == '/') return -1;
    else return 1;
}

void push(char s[], char c) {
    s[++top] = c;
}

char pop(char s[]) {
    return s[top--];
}

int main() {
    int r = 0, i = 0, j = 0;
    char infix[20], s[20], pos[20], next, temp;

    printf("Enter the infix expression (end with #):\n");
    scanf("%s", infix);

    s[top] = '#';
    next = infix[i];

    while (next != '#') {
        while (f(next) <= f(s[top])) {
            temp = pop(s);
            pos[j++] = temp;
            r += rankVal(temp);
            if (r < 1) {
                printf("invalid");
                exit(0);
            }
        }
        push(s, next);
        i++;
        next = infix[i];
    }

    while (s[top] != '#') {
        temp = pop(s);
        pos[j++] = temp;
        r += rankVal(temp);
        if (r < 1) {
            printf("invalid");
            exit(0);
        }
    }

    pos[j] = '\0';

    if (r == 1)
        printf("Postfix Expression: %s\n", pos);
    else
        printf("invalid");

    return 0;
}
