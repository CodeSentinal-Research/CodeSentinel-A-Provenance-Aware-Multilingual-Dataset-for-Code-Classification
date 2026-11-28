#include <stdio.h>
#include <string.h>
#include <stdlib.h>
typedef struct { int list[256]; int count; } List;
int cmp(const void* a, const void* b) { return (*(int*)a - *(int*)b); }
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
                    if (c == '+') res.list[res.count++] = left.list[l] + right.list[r];
                    else if (c == '-') res.list[res.count++] = left.list[l] - right.list[r];
                    else if (c == '*') res.list[res.count++] = left.list[l] * right.list[r];
                }
            }
        }
    }
    if (res.count == 0) res.list[res.count++] = atoi(expr);
    return res;
}
int main() {
    char expr[64];
    if (scanf("%63s", expr) == 1) {
        List res = diff_ways(expr);
        qsort(res.list, res.count, sizeof(int), cmp);
        for (int i = 0; i < res.count; i++) printf("%d%s", res.list[i], i == res.count - 1 ? "" : " ");
        printf("\n");
    }
    return 0;
}