#include <stdio.h>
#include <string.h>

int main() {
    char s1[100001], s2[100001];
    scanf("%s %s", s1, s2);
    int n1 = strlen(s1), n2 = strlen(s2);
    
    int dp[n1 + 1][n2 + 1];
    for (int i = 0; i <= n1; i++)
        for (int j = 0; j <= n2; j++)
            dp[i][j] = 0;
            
    int max_len = 0;
    for (int i = 1; i <= n1; i++) {
        for (int j = 1; j <= n2; j++) {
            if (s1[i-1] == s2[j-1]) {
                dp[i][j] = dp[i-1][j-1] + 1;
                if (dp[i][j] > max_len) max_len = dp[i][j];
            }
        }
    }
    printf("%d\n", max_len);
    return 0;
}
