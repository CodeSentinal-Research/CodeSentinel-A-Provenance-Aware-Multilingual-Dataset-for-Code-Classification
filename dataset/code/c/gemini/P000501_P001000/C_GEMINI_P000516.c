#include <stdio.h>
#include <stdlib.h>
#define MAX_N 100005
int nums[MAX_N], sorted_nums[MAX_N];
int cmp(const void* a, const void* b) { return (*(int*)a - *(int*)b); }
int main() {
    int n;
    if (scanf("%d", &n) == 1) {
        for (int i = 0; i < n; i++) { scanf("%d", &nums[i]); sorted_nums[i] = nums[i]; }
        qsort(sorted_nums, n, sizeof(int), cmp);
        int l = 0, r = n - 1;
        while (l < n && nums[l] == sorted_nums[l]) l++;
        while (r > l && nums[r] == sorted_nums[r]) r--;
        printf("%d\n", r >= l ? r - l + 1 : 0);
    }
    return 0;
}