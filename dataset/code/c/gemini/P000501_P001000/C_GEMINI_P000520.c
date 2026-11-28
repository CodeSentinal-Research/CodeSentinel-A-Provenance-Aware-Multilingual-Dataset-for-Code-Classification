#include <stdio.h>
#define MAX_N 100005
char s[MAX_N], st[MAX_N];
int main() {
    if (scanf("%100004s", s) == 1) {
        int top = -1;
        for (int i = 0; s[i]; i++) {
            if (s[i] == '*') {
                if (top >= 0) top--;
            } else {
                st[++top] = s[i];
            }
        }
        st[top + 1] = '\0';
        printf("%s\n", st);
    }
    return 0;
}