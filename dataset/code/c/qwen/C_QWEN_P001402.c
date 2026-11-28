#include <stdio.h>

int main() {
    int n, k;
    scanf("%d %d", &n, &k);
    int nums[n];
    int count[k];
    for (int i = 0; i < k; i++) count[i] = 0;
    
    for (int i = 0; i < n; i++) {
        scanf("%d", &nums[i]);
        count[((nums[i] % k) + k) % k]++;
    }
    
    int possible = 1;
    for (int i = 0; i <= k / 2; i++) {
        if (i == 0 || i == k - i) {
            if (count[i] % 2 != 0) possible = 0;
        } else {
            if (count[i] != count[k - i]) possible = 0;
        }
    }
    printf("%s\n", possible ? "YES" : "NO");
    return 0;
}
