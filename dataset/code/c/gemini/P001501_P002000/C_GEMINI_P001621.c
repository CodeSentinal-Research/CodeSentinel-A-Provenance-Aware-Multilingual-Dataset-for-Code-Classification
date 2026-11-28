#include <stdio.h>

int main() {
    char s[10005];
    if (scanf("%s", s) == 1) {
        long long cur = 0;
        for (int i = 0; s[i]; i++) {
            cur += s[i] - 'a' + 1;
            printf("%lld%s", cur, s[i + 1] ? " " : "");
        }
        printf("\n");
    }
    return 0;
}