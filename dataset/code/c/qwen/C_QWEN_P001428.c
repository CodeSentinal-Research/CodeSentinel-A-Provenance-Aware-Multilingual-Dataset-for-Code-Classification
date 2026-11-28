#include <stdio.h>

int main() {
    int n;
    scanf("%d", &n);
    int nums[n];
    int count[1000001] = {0};
    for (int i = 0; i < n; i++) {
        scanf("%d", &nums[i]);
        count[nums[i]]++;
    }
    
    long long total = 0;
    for (int p = 1; p <= 1000000; p *= 2) {
        for (int i = 0; i < n; i++) {
            int target = p - nums[i];
            if (target >= 0 && target <= 1000000) {
                if (target == nums[i]) total += count[target] - 1;
                else total += count[target];
            }
        }
    }
    printf("%lld\n", total / 2);
    return 0;
}
