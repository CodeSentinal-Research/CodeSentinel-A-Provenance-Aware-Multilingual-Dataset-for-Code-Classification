#include <stdio.h>
#include <string.h>
#include <stdlib.h>
char results[1024][128];
int res_count = 0;
int cmp(const void* a, const void* b) { return strcmp((char*)a, (char*)b); }
typedef struct {
    char list[128][128];
    int count;
} List;
List diff_ways(char* expr) {
    List res; res.count = 0;
    int len = strlen(expr);
    for (int i = 0; i < len; i++) {
        char c = expr[i];
        if (c == '+' || c == '-' || c == '*') {
            char left_expr[64], right_expr[64];
            strncpy(left_expr, expr, i); left_expr[i] = '\0';
            strcpy(right_expr, expr + i + 1);
            List left = diff_ways(left_expr);
            List right = diff_ways(right_expr);
            for (int l = 0; l < left.count; l++) {
                for (int r = 0; r < right.count; r++) {
                    sprintf(res.list[res.count++], "(%s%c%s)", left.list[l], c, right.list[r]);
                }
            }
        }
    }
    if (res.count == 0) {
        strcpy(res.list[res.count++], expr);
    }
    return res;
}
int main() {
    char expr[64];
    if (scanf("%63s", expr) == 1) {
        List res = diff_ways(expr);
        qsort(res.list, res.count, sizeof(res.list[0]), cmp);
        for (int i = 0; i < res.count; i++) {
            if (i == 0 || strcmp(res.list[i], res.list[i - 1]) != 0) {
                printf("%s\n", res.list[i]);
            }
        }
    }
    return 0;
}