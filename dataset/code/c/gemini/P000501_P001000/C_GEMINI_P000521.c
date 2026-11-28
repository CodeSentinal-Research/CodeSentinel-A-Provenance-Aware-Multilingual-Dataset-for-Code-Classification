#include <stdio.h>
#define MAX_N 10005
int nums[MAX_N], rem[MAX_N];
int main() {
    int n;
    if (scanf("%d", &n) == 1) {
        for (int i = 0; i < n; i++) scanf("%d", &nums[i]);
        int passes = 0, size = n;
        while (size > 0) {
            passes++;
            int rem_size = 0;
            int last = -2000000000;
            for (int i = 0; i < size; i++) {
                if (nums[i] > last) {
                    last = nums[i];
                } else {
                    rem[rem_size++] = nums[i];
                }
            }
            for (int i = 0; i < rem_size; i++) nums[i] = rem[i];
            size = rem_size;
        }
        printf("%d\n", passes);
    }
    return 0;
}