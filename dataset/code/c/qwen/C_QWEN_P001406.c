#include <stdio.h>

int main() {
    int n, key;
    scanf("%d", &n);
    int nums[n];
    for (int i = 0; i < n; i++) scanf("%d", &nums[i]);
    scanf("%d", &key);
    
    int count[1001] = {0};
    for (int i = 0; i < n - 1; i++) {
        if (nums[i] == key) count[nums[i + 1]]++;
    }
    
    int max_freq = -1, ans = -1;
    for (int i = 0; i <= 1000; i++) {
        if (count[i] > max_freq) {
            max_freq = count[i];
            ans = i;
        }
    }
    printf("%d\n", ans);
    return 0;
}
