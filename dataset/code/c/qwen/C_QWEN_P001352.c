#include <stdio.h>
#include <string.h>

char s[100005];
int k;
long long dp[100005];

int main() {
    scanf("%s%d", s, &k);
    int n = strlen(s);
    dp[0] = 1;
    for (int i = 1; i <= n; i++) {
        long long num = 0;
        for (int j = i - 1; j >= 0; j--) {
            num = num * 10 + (s[j] - '0');
            if (num > k || num == 0) break;
            dp[i] = (dp[i] + dp[j]) % 1000000007;
        }
    }
    printf("%lld\n", dp[n]);
    return 0;
}
