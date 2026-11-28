#include <stdio.h>

int main() {
    int n;
    scanf("%d", &n);
    int nums[n];
    for (int i = 0; i < n; i++) scanf("%d", &nums[i]);
    
    int idx = 0;
    for (int i = 0; i < n; i++) {
        if (nums[i] != 0) nums[idx++] = nums[i];
    }
    while (idx < n) nums[idx++] = 0;
    
    for (int i = 0; i < n; i++) printf("%d ", nums[i]);
    printf("\n");
    return 0;
}
