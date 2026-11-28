#include <stdio.h>
#include <stdlib.h>

int main() {
    int n, k;
    if (scanf("%d %d", &n, &k) == 2) {
        int* nums = (int*)malloc(n * sizeof(int));
        for (int i = 0; i < n; i++) scanf("%d", &nums[i]);

        int* dq = (int*)malloc(n * sizeof(int));
        int head = 0, tail = 0;

        for (int i = 0; i < n; i++) {
            while (tail > head && nums[dq[tail - 1]] >= nums[i]) tail--;
            dq[tail++] = i;

            while (dq[head] <= i - k) head++;

            if (i >= k - 1) {
                printf("%d%s", nums[dq[head]], i == n - 1 ? "" : " ");
            }
        }
        printf("\n");
        free(nums);
        free(dq);
    }
    return 0;
}