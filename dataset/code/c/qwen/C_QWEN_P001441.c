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
    
    int total = 0;
    for (int i = 0; i <= 100000; i++) {
        if (count[i] > 0) {
            if (k == 0) total += count[i] * (count[i] - 1) / 2;
            else if (i + k <= 100000 && count[i + k] > 0) total += count[i] * count[i + k];
        }
    }
    printf("%d\n", total);
    return 0;
}
