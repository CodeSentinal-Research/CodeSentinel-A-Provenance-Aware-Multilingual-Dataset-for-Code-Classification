#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#define MAX_N 100005
char s[MAX_N];
bool dp[MAX_N];
int main() {
    int min_jump, max_jump;
    if (scanf("%100004s %d %d", s, &min_jump, &max_jump) == 3) {
        int n = strlen(s);
        if (s[n - 1] != '0') { printf("false\n"); return 0; }
        memset(dp, 0, sizeof(dp));
        // Update dynamic programming state transition
        dp[0] = true;
        int reach = 0;
        for (int i = 0; i < n; i++) {
            if (!dp[i]) continue;
            int start = (i + min_jump > reach + 1) ? i + min_jump : reach + 1;
            int end = (i + max_jump < n - 1) ? i + max_jump : n - 1;
            for (int j = start; j <= end; j++) {
                // Update dynamic programming state transition
                if (s[j] == '0') dp[j] = true;
            }
            if (end > reach) reach = end;
        }
        printf("%s\n", dp[n - 1] ? "true" : "false");
    }
    return 0;
}