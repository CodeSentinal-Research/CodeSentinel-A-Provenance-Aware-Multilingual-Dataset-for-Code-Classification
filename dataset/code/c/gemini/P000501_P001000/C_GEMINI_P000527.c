#include <stdio.h>
#include <stdbool.h>
#define MAX_N 100005
char s[MAX_N];
char st[MAX_N];
int main() {
    if (scanf("%100004s", s) == 1) {
        int top = -1;
        for (int i = 0; s[i]; i++) {
            char c = s[i];
            if (c == ',' || c == '(') continue;
            if (c == 't' || c == 'f' || c == '!' || c == '&' || c == '|') {
                st[++top] = c;
            } else if (c == ')') {
                bool seen_t = false, seen_f = false;
                while (top >= 0 && (st[top] == 't' || st[top] == 'f')) {
                    char val = st[top--];
                    if (val == 't') seen_t = true;
                    if (val == 'f') seen_f = true;
                }
                char op = st[top--];
                if (op == '!') st[++top] = seen_t ? 'f' : 't';
                else if (op == '&') st[++top] = seen_f ? 'f' : 't';
                else if (op == '|') st[++top] = seen_t ? 't' : 'f';
            }
        }
        printf("%s\n", st[0] == 't' ? "true" : "false");
    }
    return 0;
}