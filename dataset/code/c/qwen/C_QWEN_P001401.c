#include <stdio.h>

int main() {
    int n, k;
    scanf("%d %d", &n, &k);
    int nums[n];
    for (int i = 0; i < n; i++) scanf("%d", &nums[i]);
    
    int max_len = 0;
    for (int i = 0; i < n; i++) {
        long long sum = 0;
        for (int j = i; j < n; j++) {
            sum += nums[j];
            if (sum == k) {
                if (j - i + 1 > max_len) max_len = j - i + 1;
            }
        }
    }
    printf("%d\n", max_len);
    return 0;
}
