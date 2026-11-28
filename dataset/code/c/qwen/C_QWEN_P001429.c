#include <stdio.h>

int main() {
    int n;
    scanf("%d", &n);
    int nums[n];
    for (int i = 0; i < n; i++) scanf("%d", &nums[i]);
    
    long long count = 0;
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            long long prod = (long long)nums[i] * nums[j];
            for (int k = j + 1; k < n; k++) {
                for (int l = k + 1; l < n; l++) {
                    if ((long long)nums[k] * nums[l] == prod) count++;
                }
            }
        }
    }
    printf("%lld\n", count * 8);
    return 0;
}
