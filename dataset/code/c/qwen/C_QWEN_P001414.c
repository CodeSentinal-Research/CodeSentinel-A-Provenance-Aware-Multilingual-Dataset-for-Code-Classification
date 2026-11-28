#include <stdio.h>
#include <stdlib.h>

int main() {
    int n;
    scanf("%d", &n);
    int nums[n];
    for (int i = 0; i < n; i++) scanf("%d", &nums[i]);
    
    int present[200001] = {0};
    int count = 0;
    for (int i = 0; i < n; i++) {
        int val = abs(nums[i]);
        if (!present[val]) {
            present[val] = 1;
            count++;
        }
    }
    printf("%d\n", count);
    return 0;
}
