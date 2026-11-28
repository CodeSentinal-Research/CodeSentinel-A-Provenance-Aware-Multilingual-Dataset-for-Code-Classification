#include <stdio.h>
#include <string.h>

char s[25];

int solve(int i, long long last) {
    if (i == strlen(s)) return 1;
    long long num = 0;
    for (int k = i; k < strlen(s); k++) {
        num = num * 10 + (s[k] - '0');
        if (last != -1 && num != last - 1) break;
        if (solve(k + 1, num)) return 1;
        if (num == 0) break;
    }
    return 0;
}

int main() {
    scanf("%s", s);
    printf("%s\n", solve(0, -1) ? "YES" : "NO");
    return 0;
}
