#include <stdio.h>
#include <string.h>
#define MAX_N 10005
char s[MAX_N];
char st[MAX_N];
int main() {
    if (scanf("%10004s", s) == 1) {
        int top = -1;
        for (int i = 0; s[i]; i++) {
            if (s[i] == ')') {
                char temp[MAX_N];
                int tlen = 0;
                while (top >= 0 && st[top] != '(') {
                    temp[tlen++] = st[top--];
                }
                top--; // pop '('
                for (int j = 0; j < tlen; j++) st[++top] = temp[j];
            } else {
                st[++top] = s[i];
            }
        }
        st[top + 1] = '\0';
        printf("%s\n", st);
    }
    return 0;
}