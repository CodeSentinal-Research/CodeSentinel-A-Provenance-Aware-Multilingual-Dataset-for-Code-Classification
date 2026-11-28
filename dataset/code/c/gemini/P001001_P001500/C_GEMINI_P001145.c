#include <stdio.h>
#include <stdlib.h>

#define MAX(a, b) ((a) > (b) ? (a) : (b))

int main() {
    int n;
    if (scanf("%d", &n) == 1) {
        int* nums = (int*)malloc(n * sizeof(int));
        for (int i = 0; i < n; i++) scanf("%d", &nums[i]);

        int* inc = (int*)malloc(n * sizeof(int));
        for (int i = 0; i < n; i++) {
            inc[i] = 1;
            for (int j = 0; j < i; j++) {
                if (nums[j] < nums[i]) inc[i] = MAX(inc[i], inc[j] + 1);
            }
        }

        int* dec = (int*)malloc(n * sizeof(int));
        for (int i = n - 1; i >= 0; i--) {
            dec[i] = 1;
            for (int j = n - 1; j > i; j--) {
                if (nums[j] < nums[i]) dec[i] = MAX(dec[i], dec[j] + 1);
            }
        }

        int ans = 0;
        for (int i = 0; i < n; i++) {
            ans = MAX(ans, inc[i] + dec[i] - 1);
        }
        printf("%d\n", ans);
        free(nums);
        free(inc);
        free(dec);
    }
    return 0;
}