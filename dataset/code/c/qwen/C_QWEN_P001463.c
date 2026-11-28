#include <stdio.h>

int main() {
    int n, val;
    scanf("%d %d", &n, &val);
    int nums[n];
    for (int i = 0; i < n; i++) scanf("%d", &nums[i]);
    
    int idx = 0;
    for (int i = 0; i < n; i++) {
        if (nums[i] != val) nums[idx++] = nums[i];
    }
    printf("%d\n", idx);
    for (int i = 0; i < idx; i++) printf("%d ", nums[i]);
    printf("\n");
    return 0;
}
