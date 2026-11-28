#include <stdio.h>
#define MAX_N 100005
char s[MAX_N];
int st[MAX_N];
int main() {
    if (scanf("%100004s", s) == 1) {
        int top = 0;
        st[0] = -1;
        int max_len = 0;
        for (int i = 0; s[i]; i++) {
            if (s[i] == '(') {
                st[++top] = i;
            } else {
                top--;
                if (top == -1) {
                    st[++top] = i;
                } else {
                    int len = i - st[top];
                    if (len > max_len) max_len = len;
                }
            }
        }
        printf("%d\n", max_len);
    }
    return 0;
}