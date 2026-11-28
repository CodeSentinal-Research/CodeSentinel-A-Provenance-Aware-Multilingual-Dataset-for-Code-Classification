#include <stdio.h>
#include <string.h>
#include <stdlib.h>
char num[32];
long long target;
char results[1024][128];
int res_count = 0;
int cmp(const void* a, const void* b) { return strcmp((char*)a, (char*)b); }
void add_ops(int idx, char* expr, int expr_len, long long cur_val, long long prev_op) {
    if (num[idx] == '\0') {
        if (cur_val == target) {
            expr[expr_len] = '\0';
            strcpy(results[res_count++], expr);
        }
        return;
    }
    long long v = 0;
    for (int i = idx; num[i]; i++) {
        if (i > idx && num[idx] == '0') break;
        v = v * 10 + (num[i] - '0');
        int part_len = i - idx + 1;
        char part[32]; strncpy(part, num + idx, part_len); part[part_len] = '\0';
        if (idx == 0) {
            strcpy(expr, part);
            add_ops(i + 1, expr, part_len, v, v);
        } else {
            char next_expr[128];
            sprintf(next_expr, "%s+%s", expr, part);
            add_ops(i + 1, next_expr, strlen(next_expr), cur_val + v, v);
            sprintf(next_expr, "%s-%s", expr, part);
            add_ops(i + 1, next_expr, strlen(next_expr), cur_val - v, -v);
            sprintf(next_expr, "%s*%s", expr, part);
            add_ops(i + 1, next_expr, strlen(next_expr), cur_val - prev_op + prev_op * v, prev_op * v);
        }
    }
}
int main() {
    if (scanf("%31s %lld", num, &target) == 2) {
        char expr[128];
        add_ops(0, expr, 0, 0, 0);
        qsort(results, res_count, sizeof(results[0]), cmp);
        for (int i = 0; i < res_count; i++) printf("%s\n", results[i]);
    }
    return 0;
}