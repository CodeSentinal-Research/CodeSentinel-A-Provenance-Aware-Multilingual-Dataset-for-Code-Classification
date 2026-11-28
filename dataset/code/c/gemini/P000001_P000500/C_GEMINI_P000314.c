#include <stdio.h>
#include <string.h>

void convertToTitle(long long n, char* out) {
    char temp[32];
    int len = 0;
    while (n > 0) {
        n--;
        temp[len++] = 'A' + (n % 26);
        n /= 26;
    }
    for (int i = 0; i < len; i++) {
        out[i] = temp[len - 1 - i];
    }
    out[len] = '\0';
}

int main() {
    long long n;
    if (scanf("%lld", &n) == 1) {
        char res[32] = {0};
        convertToTitle(n, res);
        printf("%s\n", res);
    }
    return 0;
}