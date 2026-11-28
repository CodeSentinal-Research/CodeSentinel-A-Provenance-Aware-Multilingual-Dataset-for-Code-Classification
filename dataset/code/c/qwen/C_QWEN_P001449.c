#include <stdio.h>
#include <stdlib.h>

int main() {
    int n;
    scanf("%d", &n);
    int nums[n];
    int present[1001] = {0};
    for (int i = 0; i < n; i++) {
        scanf("%d", &nums[i]);
        present[abs(nums[i])] = 1;
    }
    
    int ans = -1;
    for (int i = 1; i <= 1000; i++) {
        if (present[i]) ans = i;
    }
    printf("%d\n", ans);
    return 0;
}
