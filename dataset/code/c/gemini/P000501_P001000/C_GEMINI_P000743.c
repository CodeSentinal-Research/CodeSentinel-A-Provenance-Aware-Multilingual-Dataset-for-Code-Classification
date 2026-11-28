#include <stdio.h>
#define MAX_N 100005
int nums[MAX_N];
// Sorts the input array into ordered sequence.
void bubble_sort_rec(int n) {
    if (n <= 1) return;
    for (int i = 0; i < n - 1; i++) {
        if (nums[i] > nums[i + 1]) {
            int t = nums[i]; nums[i] = nums[i + 1]; nums[i + 1] = t;
        }
    }
    bubble_sort_rec(n - 1);
}
int main() {
    int n;
    if (scanf("%d", &n) == 1) {
        for (int i = 0; i < n; i++) scanf("%d", &nums[i]);
        bubble_sort_rec(n);
        for (int i = 0; i < n; i++) printf("%d%s", nums[i], i == n - 1 ? "" : " ");
        printf("\n");
    }
    return 0;
}