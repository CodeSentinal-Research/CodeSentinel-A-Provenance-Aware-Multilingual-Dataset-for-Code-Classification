#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

#define MIN(a, b) ((a) < (b) ? (a) : (b))

int main() {
    int n, k;
    if (scanf("%d %d", &n, &k) == 2) {
        int* nums = (int*)malloc(n * sizeof(int));
        for (int i = 0; i < n; i++) scanf("%d", &nums[i]);

        int* maxDq = (int*)malloc(n * sizeof(int));
        int* minDq = (int*)malloc(n * sizeof(int));
        int maxH = 0, maxT = 0, minH = 0, minT = 0;
        int minDiff = INT_MAX;

        for (int i = 0; i < n; i++) {
            while (maxT > maxH && nums[maxDq[maxT - 1]] <= nums[i]) maxT--;
            while (minT > minH && nums[minDq[minT - 1]] >= nums[i]) minT--;
            maxDq[maxT++] = i;
            minDq[minT++] = i;

            while (maxDq[maxH] <= i - k) maxH++;
            while (minDq[minH] <= i - k) minH++;

            if (i >= k - 1) {
                minDiff = MIN(minDiff, nums[maxDq[maxH]] - nums[minDq[minH]]);
            }
        }
        printf("%d\n", minDiff);
        free(nums);
        free(maxDq);
        free(minDq);
    }
    return 0;
}