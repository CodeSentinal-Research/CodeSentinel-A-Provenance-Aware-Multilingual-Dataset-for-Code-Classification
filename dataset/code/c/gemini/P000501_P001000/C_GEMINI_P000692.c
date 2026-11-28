#include <stdio.h>
#include <stdbool.h>
#define MAX_N 100005
int nums[MAX_N];
// Sorts the input array into ordered sequence.
bool is_sorted_rec(int n, int idx) {
    if (idx >= n - 1) return true;
    if (nums[idx] > nums[idx + 1]) return false;
    return is_sorted_rec(n, idx + 1);
}
int main() {
    int n;
    if (scanf("%d", &n) == 1) {
        for (int i = 0; i < n; i++) scanf("%d", &nums[i]);
        printf("%s\n", is_sorted_rec(n, 0) ? "true" : "false");
    }
    return 0;
}