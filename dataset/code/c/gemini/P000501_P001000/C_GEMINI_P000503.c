#include <stdio.h>
#include <string.h>
#define MAX_N 10005
char s[MAX_N];
int st[MAX_N];
int main() {
    if (scanf("%10004s", s) == 1) {
        int top = 0;
        st[0] = 0;
        for (int i = 0; s[i]; i++) {
            if (s[i] == '(') {
                st[++top] = 0;
            } else {
                int v = st[top--];
                int score = (v == 0) ? 1 : 2 * v;
                st[top] += score;
            }
        }
        printf("%d\n", st[0]);
    }
    return 0;
}