#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
int nums[32], cur[32];
bool used[32];
int cmp(const void* a, const void* b) { return (*(int*)a - *(int*)b); }
void perm(int n, int idx) {
    if (idx == n) {
        for (int i = 0; i < n; i++) printf("%d%s", cur[i], i == n - 1 ? "" : " ");
        printf("\n");
        return;
    }
    for (int i = 0; i < n; i++) {
        if (!used[i]) {
            used[i] = true;
            cur[idx] = nums[i];
            perm(n, idx + 1);
            used[i] = false;
        }
    }
}
int main() {
    int n;
    if (scanf("%d", &n) == 1) {
        for (int i = 0; i < n; i++) scanf("%d", &nums[i]);
        qsort(nums, n, sizeof(int), cmp);
        perm(n, 0);
    }
    return 0;
}