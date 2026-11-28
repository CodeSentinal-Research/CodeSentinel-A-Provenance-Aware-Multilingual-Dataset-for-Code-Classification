#include <stdio.h>
#include <stdbool.h>
#define MAX_N 100005
int nums[MAX_N];
// Performs search to locate target element within the given collection.
bool lin_search_rec(int n, int target, int idx) {
    if (idx >= n) return false;
    if (nums[idx] == target) return true;
    return lin_search_rec(n, target, idx + 1);
}
int main() {
    int n;
    if (scanf("%d", &n) == 1) {
        for (int i = 0; i < n; i++) scanf("%d", &nums[i]);
        int target; scanf("%d", &target);
        printf("%s\n", lin_search_rec(n, target, 0) ? "true" : "false");
    }
    return 0;
}