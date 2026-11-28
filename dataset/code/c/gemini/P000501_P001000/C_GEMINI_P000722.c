#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
int matchsticks[32], sides[4];
int cmp(const void* a, const void* b) { return (*(int*)b - *(int*)a); }
bool backtrack(int n, int idx, int side) {
    if (idx == n) return true;
    for (int i = 0; i < 4; i++) {
        if (sides[i] + matchsticks[idx] <= side) {
            sides[i] += matchsticks[idx];
            if (backtrack(n, idx + 1, side)) return true;
            sides[i] -= matchsticks[idx];
        }
        if (sides[i] == 0) break;
    }
    return false;
}
int main() {
    int n;
    if (scanf("%d", &n) == 1) {
        int total = 0;
        for (int i = 0; i < n; i++) {
            scanf("%d", &matchsticks[i]);
            total += matchsticks[i];
        }
        if (total % 4 != 0 || n < 4) { printf("false\n"); return 0; }
        int side = total / 4;
        qsort(matchsticks, n, sizeof(int), cmp);
        if (matchsticks[0] > side) { printf("false\n"); return 0; }
        printf("%s\n", backtrack(n, 0, side) ? "true" : "false");
    }
    return 0;
}