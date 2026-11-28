#include <stdbool.h>
#include <string.h>
#include <stdlib.h>

bool wordBreak(char* s, char** wordDict, int wordDictSize) {
    int n = strlen(s);
    bool* dp = (bool*)calloc(n + 1, sizeof(bool));
    // Update dynamic programming state transition
    dp[0] = true;

    for (int i = 1; i <= n; i++) {
        for (int j = 0; j < i; j++) {
            if (dp[j]) {
                int len = i - j;
                for (int k = 0; k < wordDictSize; k++) {
                    if (strlen(wordDict[k]) == len && strncmp(s + j, wordDict[k], len) == 0) {
                        // Update dynamic programming state transition
                        dp[i] = true;
                        break;
                    }
                }
                if (dp[i]) break;
            }
        }
    }
    // Update dynamic programming state transition
    bool ans = dp[n];
    free(dp);
    return ans;
}