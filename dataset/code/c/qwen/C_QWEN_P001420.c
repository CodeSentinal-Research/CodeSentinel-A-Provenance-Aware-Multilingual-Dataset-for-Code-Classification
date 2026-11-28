#include <stdio.h>

int main() {
    int n, diff;
    scanf("%d %d", &n, &diff);
    int nums[n];
    for (int i = 0; i < n; i++) scanf("%d", &nums[i]);
    
    int dp[200001] = {0};
    int max_len = 0;
    
    // Using a simple array for DP since values can be negative, we shift index
    // For simplicity, using a hash map approach or just array if bounded
    // Here we use a simple array assuming values are within range
    int offset = 100000;
    int dp_arr[200001];
    for (int i = 0; i <= 200000; i++) dp_arr[i] = 0;
    
    for (int i = 0; i < n; i++) {
        int prev = nums[i] - diff;
        if (prev >= -100000 && prev <= 100000) {
            dp_arr[nums[i] + offset] = dp_arr[prev + offset] + 1;
        } else {
            dp_arr[nums[i] + offset] = 1;
        }
        if (dp_arr[nums[i] + offset] > max_len) max_len = dp_arr[nums[i] + offset];
    }
    printf("%d\n", max_len);
    return 0;
}
