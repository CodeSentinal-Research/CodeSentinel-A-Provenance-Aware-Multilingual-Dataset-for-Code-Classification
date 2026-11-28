#include <stdio.h>
#include <stdlib.h>

int cmpDiff(const void* a, const void* b) {
    return (*(int*)a - *(int*)b);
}

int main() {
    int n, k;
    if (scanf("%d %d", &n, &k) == 2) {
        int* nums = (int*)malloc(n * sizeof(int));
        for (int i = 0; i < n; i++) scanf("%d", &nums[i]);

        int* win = (int*)malloc(k * sizeof(int));
        for (int i = 0; i <= n - k; i++) {
            for (int j = 0; j < k; j++) win[j] = nums[i + j];
            qsort(win, k, sizeof(int), cmpDiff);

            long long sum = 0;
            for (int a = 0; a < k; a++) {
                for (int b = a + 1; b < k; b++) {
                    sum += abs(win[a] - win[b]);
                }
            }
            printf("%lld%s", sum, i == n - k ? "" : " ");
        }
        printf("\n");
        free(nums);
        free(win);
    }
    return 0;
}