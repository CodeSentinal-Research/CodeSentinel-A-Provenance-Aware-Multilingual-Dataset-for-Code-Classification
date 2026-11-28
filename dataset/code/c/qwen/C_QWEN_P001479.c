#include <stdio.h>

int main() {
    int n;
    scanf("%d", &n);
    int nums[n];
    for (int i = 0; i < n; i++) scanf("%d", &nums[i]);
    
    int l = 0, r = n - 1;
    while (l < n - 1 && nums[l] <= nums[l+1]) l++;
    while (r > 0 && nums[r] >= nums[r-1]) r--;
    
    if (l >= r) printf("0\n");
    else {
        int min_val = nums[l], max_val = nums[l];
        for (int i = l; i <= r; i++) {
            if (nums[i] < min_val) min_val = nums[i];
            if (nums[i] > max_val) max_val = nums[i];
        }
        while (l > 0 && nums[l-1] > min_val) l--;
        while (r < n - 1 && nums[r+1] < max_val) r++;
        printf("%d\n", r - l + 1);
    }
    return 0;
}
