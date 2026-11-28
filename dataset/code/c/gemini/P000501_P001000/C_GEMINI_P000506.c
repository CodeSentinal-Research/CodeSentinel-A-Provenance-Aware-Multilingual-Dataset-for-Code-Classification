#include <stdio.h>
#include <string.h>
#include <ctype.h>
#define MAX_N 100005
char s[MAX_N];
int idx_c = 0;
long long parse() {
    long long st[1000];
    int top = -1;
    long long num = 0;
    char sign = '+';
    while (s[idx_c]) {
        char c = s[idx_c++];
        if (isdigit(c)) num = num * 10 + (c - '0');
        if (c == '(') num = parse();
        if (c == '+' || c == '-' || c == '*' || c == '/' || c == ')' || s[idx_c] == '\0' || s[idx_c] == '\n') {
            if (sign == '+') st[++top] = num;
            else if (sign == '-') st[++top] = -num;
            else if (sign == '*') st[top] = st[top] * num;
            else if (sign == '/') st[top] = st[top] / num;
            if (c == ')') break;
            sign = c;
            num = 0;
        }
    }
    long long sum = 0;
    for (int i = 0; i <= top; i++) sum += st[i];
    return sum;
}
int main() {
    if (fgets(s, sizeof(s), stdin)) {
        idx_c = 0;
        printf("%lld\n", parse());
    }
    return 0;
}