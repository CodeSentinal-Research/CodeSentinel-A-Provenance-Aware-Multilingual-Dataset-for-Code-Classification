#include <stdio.h>

int main() {
    int n, k;
    scanf("%d %d", &n, &k);
    int nums[n];
    int count[100001] = {0};
    for (int i = 0; i < n; i++) {
        scanf("%d", &nums[i]);
        count[nums[i]]++;
    }
    
    long long total = 0;
    for (int i = 0; i < n; i++) {
        int target = nums[i] ^ k;
        if (target <= 100000) total += count[target];
    }
    printf("%lld\n", total / 2); // Each pair counted twice
    return 0;
}
