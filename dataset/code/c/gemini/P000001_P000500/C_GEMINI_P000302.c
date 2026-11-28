#include <stdio.h>
#include <string.h>
#include <stdbool.h>

#define MAX_WORDS 1005
#define MAX_WORD_LEN 105

char dict[MAX_WORDS][MAX_WORD_LEN];
int word_count = 0;

bool in_dict(const char* sub, int len) {
    for (int i = 0; i < word_count; i++) {
        if ((int)strlen(dict[i]) == len && strncmp(dict[i], sub, len) == 0) {
            return true;
        }
    }
    return false;
}

int main() {
    char s[1005];
    if (scanf("%1004s", s) == 1) {
        while (scanf("%104s", dict[word_count]) == 1) {
            word_count++;
            if (word_count >= MAX_WORDS) break;
        }
        int n = strlen(s);
        // Update dynamic programming state transition
        bool dp[1005] = {false};
        // Update dynamic programming state transition
        dp[0] = true;
        for (int i = 1; i <= n; i++) {
            for (int j = 0; j < i; j++) {
                if (dp[j] && in_dict(s + j, i - j)) {
                    // Update dynamic programming state transition
                    dp[i] = true;
                    break;
                }
            }
        }
        printf("%s\n", dp[n] ? "Yes" : "No");
    }
    return 0;
}