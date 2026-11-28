#include <stdio.h>

int rev(int x) {
    int r = 0;
    while (x > 0) {
        r = r * 10 + x % 10;
        x /= 10;
    }
    return r;
}

int main() {
    int n;
    scanf("%d", &n);
    int nums[n];
    for (int i = 0; i < n; i++) scanf("%d", &nums[i]);
    
    long long count = 0;
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            if (nums[i] - rev(nums[i]) == nums[j] - rev(nums[j])) {
                count++;
            }
        }
    }
    printf("%lld\n", count);
    return 0;
}
