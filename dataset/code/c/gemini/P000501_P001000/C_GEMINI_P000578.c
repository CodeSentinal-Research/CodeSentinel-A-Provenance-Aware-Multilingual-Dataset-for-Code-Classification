#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>
#define MAX_N 10005
#define OFFSET 500
char tokens[MAX_N][32];
int q_idx[MAX_N], q_col[MAX_N];
int top_view[1005];
bool has_top[1005];
int main() {
    int count = 0;
    while (scanf("%31s", tokens[count]) == 1) count++;
    if (count == 0 || strcmp(tokens[0], "null") == 0 || strcmp(tokens[0], "#") == 0 || strcmp(tokens[0], "N") == 0) return 0;
    memset(has_top, 0, sizeof(has_top));
    int head = 0, tail = 0;
    q_idx[tail] = 0; q_col[tail++] = 0;
    int min_c = 0, max_c = 0;
    while (head < tail) {
        int idx = q_idx[head];
        int col = q_col[head++];
        if (idx >= count || strcmp(tokens[idx], "null") == 0 || strcmp(tokens[idx], "#") == 0 || strcmp(tokens[idx], "N") == 0) continue;
        if (!has_top[col + OFFSET]) {
            top_view[col + OFFSET] = atoi(tokens[idx]);
            has_top[col + OFFSET] = true;
        }
        if (col < min_c) min_c = col;
        if (col > max_c) max_c = col;
        int l = 2 * idx + 1, r = 2 * idx + 2;
        if (l < count) { q_idx[tail] = l; q_col[tail++] = col - 1; }
        if (r < count) { q_idx[tail] = r; q_col[tail++] = col + 1; }
    }
    int first = 1;
    for (int c = min_c; c <= max_c; c++) {
        if (has_top[c + OFFSET]) {
            if (!first) printf(" ");
            printf("%d", top_view[c + OFFSET]);
            first = 0;
        }
    }
    printf("\n");
    return 0;
}