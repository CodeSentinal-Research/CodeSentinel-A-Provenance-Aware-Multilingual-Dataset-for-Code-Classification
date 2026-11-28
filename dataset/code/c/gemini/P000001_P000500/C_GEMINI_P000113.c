#include <stdio.h>

int removeDuplicates(int nums[], int n) {
    if (n <= 0) return 0;
    int k = 1;
    for (int i = 1; i < n; i++) {
        if (nums[i] != nums[i - 1]) {
            nums[k++] = nums[i];
        }
    }
    return k;
}

int main() {
    int n;
    if (scanf("%d", &n) == 1 && n > 0) {
        int nums[n];
        for (int i = 0; i < n; i++) scanf("%d", &nums[i]);
        int k = removeDuplicates(nums, n);
        printf("%d\n", k);
        for (int i = 0; i < k; i++) {
            printf("%d%s", nums[i], (i == k - 1 ? "" : " "));
        }
        printf("\n");
    }
    return 0;
}