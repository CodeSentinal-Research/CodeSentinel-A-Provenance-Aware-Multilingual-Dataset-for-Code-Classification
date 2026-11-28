#include <stdio.h>

int main() {
    int n;
    scanf("%d", &n);
    int nums[n];
    int count[100001] = {0};
    for (int i = 0; i < n; i++) {
        scanf("%d", &nums[i]);
        count[nums[i]]++;
    }
    
    int ans = -1;
    for (int i = 1; i <= 100000; i++) {
        if (count[i] == i && i > ans) ans = i;
    }
    printf("%d\n", ans);
    return 0;
}
