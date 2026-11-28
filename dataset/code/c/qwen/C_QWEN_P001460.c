#include <stdio.h>

int main() {
    int n;
    scanf("%d", &n);
    int nums[n];
    for (int i = 0; i < n; i++) scanf("%d", &nums[i]);
    
    int prefix[100001] = {0};
    int count[1000001] = {0};
    int xor_val = 0;
    count[0] = 1;
    long long total = 0;
    
    for (int i = 0; i < n; i++) {
        xor_val ^= nums[i];
        total += count[xor_val];
        count[xor_val]++;
    }
    printf("%lld\n", total);
    return 0;
}
