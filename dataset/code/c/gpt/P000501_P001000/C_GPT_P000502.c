#include <stdio.h>
#include <string.h>
#include <stdlib.h>

/* Evaluate Reverse Polish Notation */
int main(void) {
    int n;
    char tok[64];
    long long st[10000];
    int top = 0;
    if (scanf("%d", &n) != 1) return 1;
    for (int i = 0; i < n; i++) {
        scanf("%63s", tok);
        if (!strcmp(tok, "+") || !strcmp(tok, "-") || !strcmp(tok, "*") || !strcmp(tok, "/")) {
            long long b = st[--top], a = st[--top];
            if (tok[0] == '+') st[top++] = a + b;
            else if (tok[0] == '-') st[top++] = a - b;
            else if (tok[0] == '*') st[top++] = a * b;
            else st[top++] = a / b;
        } else {
            st[top++] = strtoll(tok, NULL, 10);
        }
    }
    printf("%lld\n", top ? st[top - 1] : 0);

    return 0;
}
