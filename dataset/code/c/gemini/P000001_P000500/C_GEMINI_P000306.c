#include <stdio.h>
#include <ctype.h>
#include <string.h>

#define MAX_STACK 2000

int calculate(const char* s) {
    int stack[MAX_STACK];
    int top = -1;
    long long num = 0;
    char sign = '+';
    int len = strlen(s);
    for (int i = 0; i < len; i++) {
        char c = s[i];
        if (isdigit(c)) {
            num = num * 10 + (c - '0');
        }
        if ((!isdigit(c) && c != ' ' && c != '\n' && c != '\r') || i == len - 1) {
            if (sign == '+') stack[++top] = num;
            else if (sign == '-') stack[++top] = -num;
            else if (sign == '*') stack[top] = stack[top] * num;
            else if (sign == '/') stack[top] = stack[top] / num;
            sign = c;
            num = 0;
        }
    }
    int total = 0;
    for (int i = 0; i <= top; i++) total += stack[i];
    return total;
}

int main() {
    char s[2005];
    if (fgets(s, sizeof(s), stdin)) {
        printf("%d\n", calculate(s));
    }
    return 0;
}