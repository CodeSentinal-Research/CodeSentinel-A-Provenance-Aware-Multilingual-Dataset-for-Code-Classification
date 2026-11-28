#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
int nums[32], subsets[32];
int cmp(const void* a, const void* b) { return (*(int*)b - *(int*)a); }
bool backtrack(int n, int idx, int k, int target) {
    if (idx == n) return true;
    for (int i = 0; i < k; i++) {
        if (subsets[i] + nums[idx] <= target) {
            subsets[i] += nums[idx];
            if (backtrack(n, idx + 1, k, target)) return true;
            subsets[i] -= nums[idx];
        }
        if (subsets[i] == 0) break;
    }
    return false;
}
int main() {
    int n;
    if (scanf("%d", &n) == 1) {
        int total = 0;
        for (int i = 0; i < n; i++) { scanf("%d", &nums[i]); total += nums[i]; }
        int k; scanf("%d", &k);
        if (total % k != 0 || n < k) { printf("false\n"); return 0; }
        int target = total / k;
        qsort(nums, n, sizeof(int), cmp);
        if (nums[0] > target) { printf("false\n"); return 0; }
        for (int i = 0; i < k; i++) subsets[i] = 0;
        printf("%s\n", backtrack(n, 0, k, target) ? "true" : "false");
    }
    return 0;
}