#include <stdio.h>
#include <stdlib.h>

#define MAX(a, b) ((a) > (b) ? (a) : (b))

int main() {
    int n, k;
    if (scanf("%d %d", &n, &k) == 2) {
        int* nums = (int*)malloc(n * sizeof(int));
        for (int i = 0; i < n; i++) scanf("%d", &nums[i]);

        int curNegs = 0;
        for (int i = 0; i < k; i++) if (nums[i] < 0) curNegs++;
        int maxNegs = curNegs;

        for (int i = k; i < n; i++) {
            if (nums[i] < 0) curNegs++;
            if (nums[i - k] < 0) curNegs--;
            maxNegs = MAX(maxNegs, curNegs);
        }
        printf("%d\n", maxNegs);
        free(nums);
    }
    return 0;
}