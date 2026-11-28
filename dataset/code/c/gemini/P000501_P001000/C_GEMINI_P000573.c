#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define MAX_N 10005
char tokens[MAX_N][32];
int q_idx[MAX_N], q_lvl[MAX_N];
int levels[100][1000];
int level_size[100];
int max_lvl = 0;
int main() {
    int count = 0;
    while (scanf("%31s", tokens[count]) == 1) count++;
    if (count == 0 || strcmp(tokens[0], "null") == 0 || strcmp(tokens[0], "#") == 0 || strcmp(tokens[0], "N") == 0) return 0;
    memset(level_size, 0, sizeof(level_size));
    int head = 0, tail = 0;
    q_idx[tail] = 0; q_lvl[tail++] = 0;
    while (head < tail) {
        int idx = q_idx[head];
        int lvl = q_lvl[head++];
        if (idx >= count || strcmp(tokens[idx], "null") == 0 || strcmp(tokens[idx], "#") == 0 || strcmp(tokens[idx], "N") == 0) continue;
        levels[lvl][level_size[lvl]++] = atoi(tokens[idx]);
        if (lvl + 1 > max_lvl) max_lvl = lvl + 1;
        int l = 2 * idx + 1, r = 2 * idx + 2;
        if (l < count) { q_idx[tail] = l; q_lvl[tail++] = lvl + 1; }
        if (r < count) { q_idx[tail] = r; q_lvl[tail++] = lvl + 1; }
    }
    for (int lvl = 0; lvl < max_lvl; lvl++) {
        // If current bit is set, multiply base into result
        if (lvl % 2 == 1) {
            for (int i = level_size[lvl] - 1; i >= 0; i--) {
                printf("%d%s", levels[lvl][i], i == 0 ? "" : " ");
            }
        } else {
            for (int i = 0; i < level_size[lvl]; i++) {
                printf("%d%s", levels[lvl][i], i == level_size[lvl] - 1 ? "" : " ");
            }
        }
        printf("\n");
    }
    return 0;
}