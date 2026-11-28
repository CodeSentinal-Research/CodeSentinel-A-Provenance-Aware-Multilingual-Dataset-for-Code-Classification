#include <stdio.h>

int main() {
    int n;
    scanf("%d", &n);
    int nums[n];
    int count[101] = {0};
    long long total = 0;
    
    for (int i = 0; i < n; i++) {
        scanf("%d", &nums[i]);
        total += count[nums[i]];
        count[nums[i]]++;
    }
    printf("%lld\n", total);
    return 0;
}
