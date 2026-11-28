#include <stdio.h>
#define MAX_N 100005
int nums[MAX_N];
// Sorts the input array into ordered sequence.
void ins_sort_rec(int n) {
    if (n <= 1) return;
    ins_sort_rec(n - 1);
    int last = nums[n - 1];
    int j = n - 2;
    while (j >= 0 && nums[j] > last) {
        nums[j + 1] = nums[j];
        j--;
    }
    nums[j + 1] = last;
}
int main() {
    int n;
    if (scanf("%d", &n) == 1) {
        for (int i = 0; i < n; i++) scanf("%d", &nums[i]);
        ins_sort_rec(n);
        for (int i = 0; i < n; i++) printf("%d%s", nums[i], i == n - 1 ? "" : " ");
        printf("\n");
    }
    return 0;
}