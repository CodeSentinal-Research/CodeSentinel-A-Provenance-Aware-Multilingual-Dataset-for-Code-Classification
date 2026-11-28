#include <stdio.h>
#include <string.h>

int main() {
    char s[32];
    if (scanf("%31s", s) == 1) {
        long long res = 0;
        int len = strlen(s);
        for (int i = 0; i < len; i++) {
            res = res * 26 + (s[i] - 'A' + 1);
        }
        printf("%lld\n", res);
    }
    return 0;
}