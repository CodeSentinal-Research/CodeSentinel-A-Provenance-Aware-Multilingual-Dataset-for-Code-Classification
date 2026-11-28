#include <stdio.h>

int main() {
    int n, target;
    scanf("%d %d", &n, &target);
    int nums[n];
    for (int i = 0; i < n; i++) scanf("%d", &nums[i]);
    
    int l = 0, r = n - 1;
    while (l < r) {
        int sum = nums[l] + nums[r];
        if (sum == target) {
            printf("%d %d\n", l + 1, r + 1);
            return 0;
        } else if (sum < target) l++;
        else r--;
    }
    return 0;
}
