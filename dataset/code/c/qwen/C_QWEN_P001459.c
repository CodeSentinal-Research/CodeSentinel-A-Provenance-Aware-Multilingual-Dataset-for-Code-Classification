#include <stdio.h>

int main() {
    int n;
    scanf("%d", &n);
    int nums[n];
    int present[100001] = {0};
    for (int i = 0; i < n; i++) {
        scanf("%d", &nums[i]);
        if (nums[i] > 0 && nums[i] <= 100000) present[nums[i]] = 1;
    }
    
    int ans = 1;
    while (ans <= 100000 && present[ans]) ans++;
    printf("%d\n", ans);
    return 0;
}
