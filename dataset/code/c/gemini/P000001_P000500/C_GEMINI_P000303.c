#include <stdio.h>
#include <string.h>
#include <stdbool.h>

#define MAX_WORDS 100
#define MAX_LEN 105

char dict[MAX_WORDS][MAX_LEN];
int dict_count = 0;

void dfs(const char* s, char* current, int curr_len) {
    if (*s == '\0') {
        current[curr_len] = '\0';
        printf("%s\n", current);
        return;
    }
    int s_len = strlen(s);
    for (int i = 0; i < dict_count; i++) {
        int w_len = strlen(dict[i]);
        if (w_len <= s_len && strncmp(s, dict[i], w_len) == 0) {
            char next_current[1005];
            strcpy(next_current, current);
            if (curr_len > 0) {
                strcat(next_current, " ");
            }
            strcat(next_current, dict[i]);
            dfs(s + w_len, next_current, strlen(next_current));
        }
    }
}

int main() {
    char s[MAX_LEN];
    if (scanf("%104s", s) == 1) {
        while (scanf("%104s", dict[dict_count]) == 1) {
            dict_count++;
            if (dict_count >= MAX_WORDS) break;
        }
        char current[1005] = {0};
        dfs(s, current, 0);
    }
    return 0;
}