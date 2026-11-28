#include <stdio.h>

int main() {
    int n;
    scanf("%d", &n);
    int nums[n];
    for (int i = 0; i < n; i++) scanf("%d", &nums[i]);
    
    int l = 0, mid = 0, r = n - 1;
    while (mid <= r) {
        if (nums[mid] == 0) { int t = nums[l]; nums[l] = nums[mid]; nums[mid] = t; l++; mid++; }
        else if (nums[mid] == 1) mid++;
        else { int t = nums[mid]; nums[mid] = nums[r]; nums[r] = t; r--; }
    }
    for (int i = 0; i < n; i++) printf("%d ", nums[i]);
    printf("\n");
    return 0;
}
