#include <stdio.h>

int main() {
    int n;
    scanf("%d", &n);
    int nums[n];
    for (int i = 0; i < n; i++) scanf("%d", &nums[i]);
    
    long long total_pairs = (long long)n * (n - 1) / 2;
    long long good_pairs = 0;
    
    int count[100001] = {0};
    for (int i = 0; i < n; i++) {
        int val = nums[i] - i;
        if (val >= 0 && val <= 100000) count[val]++;
    }
    
    for (int i = 0; i <= 100000; i++) {
        if (count[i] > 1) {
            good_pairs += (long long)count[i] * (count[i] - 1) / 2;
        }
    }
    
    printf("%lld\n", total_pairs - good_pairs);
    return 0;
}
