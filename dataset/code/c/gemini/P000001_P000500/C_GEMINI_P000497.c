#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#define MAX_N 100005
char s[MAX_N];
char st[MAX_N];
int last_occ[26];
bool seen[26];
int main() {
    if (scanf("%100004s", s) == 1) {
        for (int i = 0; s[i]; i++) last_occ[s[i] - 'a'] = i;
        int top = -1;
        for (int i = 0; s[i]; i++) {
            int c = s[i] - 'a';
            if (!seen[c]) {
                while (top >= 0 && st[top] > s[i] && i < last_occ[st[top] - 'a']) {
                    seen[st[top] - 'a'] = false;
                    top--;
                }
                seen[c] = true;
                st[++top] = s[i];
            }
        }
        st[top + 1] = '\0';
        printf("%s\n", st);
    }
    return 0;
}