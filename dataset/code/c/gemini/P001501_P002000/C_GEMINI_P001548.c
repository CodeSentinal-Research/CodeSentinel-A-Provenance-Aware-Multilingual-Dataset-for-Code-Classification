#include <stdio.h>
#include <stdlib.h>

#define MAX(a, b) ((a) > (b) ? (a) : (b))

int main() {
    int n, k;
    if (scanf("%d %d", &n, &k) == 2) {
        int* nums = (int*)malloc(n * sizeof(int));
        for (int i = 0; i < n; i++) scanf("%d", &nums[i]);

        long long curProd = 1;
        for (int i = 0; i < k; i++) curProd *= nums[i];
        long long maxProd = curProd;

        for (int i = k; i < n; i++) {
            curProd = (curProd / nums[i - k]) * nums[i];
            maxProd = MAX(maxProd, curProd);
        }
        printf("%lld\n", maxProd);
        free(nums);
    }
    return 0;
}