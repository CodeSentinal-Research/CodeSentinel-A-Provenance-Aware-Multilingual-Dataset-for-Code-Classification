#include <stdio.h>
#include <string.h>

char s[205];

int solve(int i, long long a, long long b, int cnt) {
    if (i == strlen(s)) return cnt >= 3;
    long long c = a + b;
    char cs[20];
    sprintf(cs, "%lld", c);
    int len = strlen(cs);
    if (strncmp(s + i, cs, len) == 0) {
        return solve(i + len, b, c, cnt + 1);
    }
    return 0;
}

int main() {
    scanf("%s", s);
    for (int i = 1; i < strlen(s); i++) {
        for (int j = i + 1; j < strlen(s); j++) {
            long long a = 0, b = 0;
            for (int x = 0; x < i; x++) a = a * 10 + (s[x] - '0');
            for (int x = i; x < j; x++) b = b * 10 + (s[x] - '0');
            if (solve(j, a, b, 2)) {
                printf("YES\n");
                return 0;
            }
        }
    }
    printf("NO\n");
    return 0;
}
