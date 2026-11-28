#include <stdio.h>
#include <string.h>
#define MAX_N 10005
char s[MAX_N];
char st[MAX_N];
int main() {
    if (scanf("%10004s", s) == 1) {
        int top = -1;
        int len = strlen(s);
        for (int i = len - 1; i >= 0; i--) {
            char c = s[i];
            if (top >= 0 && st[top] == '?') {
                top--; // '?'
                char first = st[top--];
                top--; // ':'
                char second = st[top--];
                st[++top] = (c == 'T') ? first : second;
            } else {
                st[++top] = c;
            }
        }
        printf("%c\n", st[0]);
    }
    return 0;
}