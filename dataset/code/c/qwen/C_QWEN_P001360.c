#include <stdio.h>
#include <string.h>

char s[100001];
int k;

int pal(int l, int r) {
    while (l < r) {
        if (s[l++] != s[r--]) return 0;
    }
    return 1;
}

int solve(int i, int rem) {
    if (rem == 0) return i == strlen(s);
    if (strlen(s) - i < rem) return 0;
    for (int j = i; j < strlen(s); j++) {
        if (pal(i, j) && solve(j + 1, rem - 1)) return 1;
    }
    return 0;
}

int main() {
    scanf("%s%d", s, &k);
    printf("%s\n", solve(0, k) ? "YES" : "NO");
    return 0;
}
