#include <stdio.h>
#include <string.h>

long long binaryToDecimal(const char* s) {
    long long res = 0;
    for (int i = 0; s[i] != '\0'; i++) {
        if (s[i] == '0' || s[i] == '1') {
            res = (res << 1) | (s[i] - '0');
        }
    }
    return res;
}

int main() {
    char s[70];
    if (scanf("%69s", s) == 1) {
        printf("%lld\n", binaryToDecimal(s));
    }
    return 0;
}