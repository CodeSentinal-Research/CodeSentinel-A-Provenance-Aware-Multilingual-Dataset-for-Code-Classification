#include <stdio.h>
#include <string.h>
#include <ctype.h>
int main() {
    char s[1005]; long long k;
    if (scanf("%1004s %lld", s, &k) == 2) {
        long long size = 0;
        int len = strlen(s);
        for (int i = 0; i < len; i++) {
            if (isdigit(s[i])) size *= (s[i] - '0');
            else size++;
        }
        for (int i = len - 1; i >= 0; i--) {
            char c = s[i];
            k %= size;
            if (k == 0 && isalpha(c)) {
                printf("%c\n", c);
                return 0;
            }
            if (isdigit(c)) size /= (c - '0');
            else size--;
        }
    }
    return 0;
}