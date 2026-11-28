#include <stdio.h>

int main() {
    int n;
    scanf("%d", &n);
    int nums[n];
    for (int i = 0; i < n; i++) scanf("%d", &nums[i]);
    
    int max_len = 0;
    int i = 0;
    while (i < n - 1) {
        while (i < n - 1 && nums[i] >= nums[i+1]) i++;
        int up_start = i;
        while (i < n - 1 && nums[i] <= nums[i+1]) i++;
        if (i == up_start) { i++; continue; }
        while (i < n - 1 && nums[i] >= nums[i+1]) i++;
        int len = i - up_start + 1;
        if (len > max_len) max_len = len;
    }
    printf("%d\n", max_len);
    return 0;
}
