#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX_N 10005
long long st[MAX_N];
int main() {
    int n;
    if (scanf("%d", &n) == 1) {
        int top = -1;
        for (int i = 0; i < n; i++) {
            char s[32];
            scanf("%31s", s);
            if (strlen(s) == 1 && (s[0] == '+' || s[0] == '-' || s[0] == '*' || s[0] == '/')) {
                long long b = st[top--];
                long long a = st[top--];
                if (s[0] == '+') st[++top] = a + b;
                else if (s[0] == '-') st[++top] = a - b;
                else if (s[0] == '*') st[++top] = a * b;
                else if (s[0] == '/') st[++top] = a / b;
            } else {
                st[++top] = atoll(s);
            }
        }
        printf("%lld\n", st[top]);
    }
    return 0;
}