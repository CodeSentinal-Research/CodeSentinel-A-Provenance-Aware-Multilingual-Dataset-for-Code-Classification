#include <stdio.h>

int n;
int a[15], sums[15];

int solve(int i, int s1, int s2, int s3, int s4) {
    if (i == n) return s1 == s2 && s2 == s3 && s3 == s4;
    if (s1 + a[i] <= s1 + s2 + s3 + s4) {
        if (solve(i + 1, s1 + a[i], s2, s3, s4)) return 1;
    }
    if (solve(i + 1, s1, s2 + a[i], s3, s4)) return 1;
    if (solve(i + 1, s1, s2, s3 + a[i], s4)) return 1;
    if (solve(i + 1, s1, s2, s3, s4 + a[i])) return 1;
    return 0;
}

int main() {
    scanf("%d", &n);
    int sum = 0;
    for (int i = 0; i < n; i++) {
        scanf("%d", &a[i]);
        sum += a[i];
    }
    if (sum % 4 != 0) {
        printf("NO\n");
        return 0;
    }
    printf("%s\n", solve(0, 0, 0, 0, 0) ? "YES" : "NO");
    return 0;
}
