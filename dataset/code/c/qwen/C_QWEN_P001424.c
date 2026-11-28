#include <stdio.h>

int main() {
    int n;
    scanf("%d", &n);
    int nums[n];
    int count[1001] = {0};
    for (int i = 0; i < n; i++) {
        scanf("%d", &nums[i]);
        count[nums[i]]++;
    }
    
    int freq_count[1001] = {0};
    for (int i = 0; i <= 1000; i++) {
        if (count[i] > 0) freq_count[count[i]]++;
    }
    
    int unique = 1;
    for (int i = 0; i <= 1000; i++) {
        if (freq_count[i] > 1) {
            unique = 0;
            break;
        }
    }
    printf("%s\n", unique ? "YES" : "NO");
    return 0;
}
