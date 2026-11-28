#include <stdio.h>

int main() {
    int n;
    scanf("%d", &n);
    int nums[n];
    for (int i = 0; i < n; i++) scanf("%d", &nums[i]);
    
    int idx = 0;
    for (int i = 0; i < n; i++) {
        if (i == 0 || nums[i] != nums[i-1]) {
            nums[idx++] = nums[i];
        }
    }
    printf("%d\n", idx);
    for (int i = 0; i < idx; i++) printf("%d ", nums[i]);
    printf("\n");
    return 0;
}
