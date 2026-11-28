#include <stdio.h>
#include <ctype.h>
#include <string.h>

#define MAX_STACK 1000

int calculate(const char* s) {
    int stack[MAX_STACK];
    int top = -1;
    long long res = 0, num = 0;
    int sign = 1;
    int len = strlen(s);
    for (int i = 0; i < len; i++) {
        char c = s[i];
        if (isdigit(c)) {
            num = num * 10 + (c - '0');
        } else if (c == '+' || c == '-') {
            res += sign * num;
            num = 0;
            sign = (c == '+') ? 1 : -1;
        } else if (c == '(') {
            stack[++top] = res;
            stack[++top] = sign;
            res = 0;
            sign = 1;
        } else if (c == ')') {
            res += sign * num;
            num = 0;
            int prevSign = stack[top--];
            int prevRes = stack[top--];
            res = prevRes + prevSign * res;
        }
    }
    res += sign * num;
    return res;
}

int main() {
    char s[2005];
    if (fgets(s, sizeof(s), stdin)) {
        printf("%d\n", calculate(s));
    }
    return 0;
}