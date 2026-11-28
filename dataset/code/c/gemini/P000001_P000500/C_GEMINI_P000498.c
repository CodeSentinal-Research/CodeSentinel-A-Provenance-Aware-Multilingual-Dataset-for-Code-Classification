#include <stdio.h>
#include <string.h>
#include <ctype.h>
#define MAX_N 100005
char s[MAX_N];
long long st[MAX_N];
int main() {
    if (fgets(s, sizeof(s), stdin)) {
        int top = -1;
        long long res = 0, num = 0, sign = 1;
        for (int i = 0; s[i]; i++) {
            if (isdigit(s[i])) {
                num = num * 10 + (s[i] - '0');
            } else if (s[i] == '+' || s[i] == '-') {
                res += sign * num;
                num = 0;
                sign = (s[i] == '+') ? 1 : -1;
            } else if (s[i] == '(') {
                st[++top] = res;
                st[++top] = sign;
                res = 0;
                sign = 1;
            } else if (s[i] == ')') {
                res += sign * num;
                num = 0;
                long long prev_sign = st[top--];
                long long prev_res = st[top--];
                res = prev_res + prev_sign * res;
            }
        }
        res += sign * num;
        printf("%lld\n", res);
    }
    return 0;
}