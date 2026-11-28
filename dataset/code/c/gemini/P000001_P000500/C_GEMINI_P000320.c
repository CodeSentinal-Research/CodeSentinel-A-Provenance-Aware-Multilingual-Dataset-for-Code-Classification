#include <stdio.h>
#include <string.h>

int main() {
    char s[1005], c;
    if (scanf("%1004s %c", s, &c) == 2) {
        int n = strlen(s);
        int res[1005];
        int prev = -100000;
        for (int i = 0; i < n; i++) {
            if (s[i] == c) prev = i;
            res[i] = i - prev;
        }
        prev = 100000;
        for (int i = n - 1; i >= 0; i--) {
            if (s[i] == c) prev = i;
            if (prev - i < res[i]) res[i] = prev - i;
        }
        for (int i = 0; i < n; i++) {
            printf("%d%s", res[i], i == n - 1 ? "" : " ");
        }
        printf("\n");
    }
    return 0;
}