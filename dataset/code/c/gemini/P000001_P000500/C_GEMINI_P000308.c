#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void diffWays(const char* expr, int* out, int* count) {
    int local_count = 0;
    int len = strlen(expr);
    for (int i = 0; i < len; i++) {
        char c = expr[i];
        if (c == '+' || c == '-' || c == '*') {
            char left_str[32], right_str[32];
            strncpy(left_str, expr, i);
            left_str[i] = '\0';
            strcpy(right_str, expr + i + 1);

            int left_res[200], left_cnt = 0;
            int right_res[200], right_cnt = 0;
            diffWays(left_str, left_res, &left_cnt);
            diffWays(right_str, right_res, &right_cnt);

            for (int l = 0; l < left_cnt; l++) {
                for (int r = 0; r < right_cnt; r++) {
                    if (c == '+') out[(*count)++] = left_res[l] + right_res[r];
                    else if (c == '-') out[(*count)++] = left_res[l] - right_res[r];
                    else if (c == '*') out[(*count)++] = left_res[l] * right_res[r];
                    local_count++;
                }
            }
        }
    }
    if (local_count == 0) {
        out[(*count)++] = atoi(expr);
    }
}

int main() {
    char s[64];
    if (scanf("%63s", s) == 1) {
        int results[1000];
        int count = 0;
        diffWays(s, results, &count);
        for (int i = 0; i < count; i++) {
            printf("%d\n", results[i]);
        }
    }
    return 0;
}