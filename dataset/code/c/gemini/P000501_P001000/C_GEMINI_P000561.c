#include <stdio.h>
#include <string.h>
#define MAX_N 100005
char s[MAX_N], res[MAX_N], q[MAX_N];
int count[26];
int main() {
    if (scanf("%100004s", s) == 1) {
        memset(count, 0, sizeof(count));
        int head = 0, tail = 0;
        int len = strlen(s);
        for (int i = 0; i < len; i++) {
            char c = s[i];
            count[c - 'a']++;
            q[tail++] = c;
            while (head < tail && count[q[head] - 'a'] > 1) head++;
            res[i] = (head < tail) ? q[head] : '#';
        }
        res[len] = '\0';
        printf("%s\n", res);
    }
    return 0;
}