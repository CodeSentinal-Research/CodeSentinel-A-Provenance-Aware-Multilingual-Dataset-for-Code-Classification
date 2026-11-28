#include <stdio.h>
#include <stdlib.h>

int cmp(const void *a, const void *b) {
    return *(int *)a - *(int *)b;
}

long long power(long long base, long long exp, long long mod) {
    long long res = 1;
    base %= mod;
    while (exp > 0) {
        if (exp % 2 == 1) res = (res * base) % mod;
        base = (base * base) % mod;
        exp /= 2;
    }
    return res;
}

int main() {
    int n, target;
    scanf("%d %d", &n, &target);
    int nums[n];
    for (int i = 0; i < n; i++) scanf("%d", &nums[i]);
    
    qsort(nums, n, sizeof(int), cmp);
    long long count = 0;
    int l = 0, r = n - 1;
    while (l <= r) {
        if (nums[l] + nums[r] <= target) {
            count = (count + power(2, r - l, 1000000007)) % 1000000007;
            l++;
        } else r--;
    }
    printf("%lld\n", count);
    return 0;
}
