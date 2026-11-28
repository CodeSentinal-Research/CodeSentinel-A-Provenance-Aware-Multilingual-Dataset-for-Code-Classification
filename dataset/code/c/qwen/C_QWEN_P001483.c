#include <stdio.h>

int main() {
    int n, k;
    scanf("%d %d", &n, &k);
    int nums[n];
    for (int i = 0; i < n; i++) scanf("%d", &nums[i]);
    
    int l = 0, zeros = 0, max_len = 0;
    for (int r = 0; r < n; r++) {
        if (nums[r] == 0) zeros++;
        while (zeros > k) { if (nums[l++] == 0) zeros--; }
        if (r - l + 1 > max_len) max_len = r - l + 1;
    }
    printf("%d\n", max_len);
    return 0;
}
