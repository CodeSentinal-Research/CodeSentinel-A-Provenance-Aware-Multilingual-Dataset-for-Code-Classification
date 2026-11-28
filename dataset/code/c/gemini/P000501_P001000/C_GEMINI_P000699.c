#include <stdio.h>
#define MAX_N 100005
int nums[MAX_N];
void rev_arr_rec(int l, int r) {
    if (l >= r) return;
    int tmp = nums[l]; nums[l] = nums[r]; nums[r] = tmp;
    rev_arr_rec(l + 1, r - 1);
}
int main() {
    int n;
    if (scanf("%d", &n) == 1) {
        for (int i = 0; i < n; i++) scanf("%d", &nums[i]);
        rev_arr_rec(0, n - 1);
        for (int i = 0; i < n; i++) printf("%d%s", nums[i], i == n - 1 ? "" : " ");
        printf("\n");
    }
    return 0;
}