#include <stdio.h>

int main() {
    int n;
    scanf("%d", &n);
    int nums[n];
    for (int i = 0; i < n; i++) scanf("%d", &nums[i]);
    
    for (int i = 0; i < n - 1; i++) {
        if (nums[i] == nums[i+1]) { nums[i] *= 2; nums[i+1] = 0; }
    }
    int idx = 0;
    for (int i = 0; i < n; i++) { if (nums[i] != 0) nums[idx++] = nums[i]; }
    while (idx < n) nums[idx++] = 0;
    
    for (int i = 0; i < n; i++) printf("%d ", nums[i]);
    printf("\n");
    return 0;
}
