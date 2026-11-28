#include <stdio.h>
#include <stdbool.h>
#define MAX_N 100005
int nums[MAX_N];
bool is_max_heap(int n, int idx) {
    int l = 2 * idx + 1, r = 2 * idx + 2;
    if (l < n) {
        if (nums[idx] < nums[l] || !is_max_heap(n, l)) return false;
    }
    if (r < n) {
        if (nums[idx] < nums[r] || !is_max_heap(n, r)) return false;
    }
    return true;
}
int main() {
    int n;
    if (scanf("%d", &n) == 1) {
        for (int i = 0; i < n; i++) scanf("%d", &nums[i]);
        printf("%s\n", is_max_heap(n, 0) ? "true" : "false");
    }
    return 0;
}