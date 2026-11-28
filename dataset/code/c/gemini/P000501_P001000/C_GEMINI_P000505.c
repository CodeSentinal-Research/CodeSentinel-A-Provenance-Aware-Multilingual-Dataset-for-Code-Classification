#include <stdio.h>
#include <string.h>
#include <ctype.h>
#define MAX_N 100005
char s[MAX_N];
long long st[MAX_N];
int main() {
    if (fgets(s, sizeof(s), stdin)) {
        int top = -1;
        long long num = 0;
        char sign = '+';
        int len = strlen(s);
        while (len > 0 && (s[len - 1] == '\n' || s[len - 1] == '\r')) len--;
        for (int i = 0; i < len; i++) {
            char c = s[i];
            if (isdigit(c)) num = num * 10 + (c - '0');
            if ((!isdigit(c) && c != ' ') || i == len - 1) {
                if (sign == '+') st[++top] = num;
                else if (sign == '-') st[++top] = -num;
                else if (sign == '*') st[top] = st[top] * num;
                else if (sign == '/') st[top] = st[top] / num;
                sign = c;
                num = 0;
            }
        }
        long long sum = 0;
        for (int i = 0; i <= top; i++) sum += st[i];
        printf("%lld\n", sum);
    }
    return 0;
}