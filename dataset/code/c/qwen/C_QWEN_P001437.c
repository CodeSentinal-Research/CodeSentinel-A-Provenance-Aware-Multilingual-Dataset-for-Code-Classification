#include <stdio.h>

int main() {
    int n;
    scanf("%d", &n);
    int nums[n];
    int present[1001] = {0};
    for (int i = 0; i < n; i++) {
        scanf("%d", &nums[i]);
        present[nums[i]] = 1;
    }
    
    int found = 0;
    for (int i = 0; i < n; i++) {
        if (nums[i] * 2 <= 1000 && present[nums[i] * 2]) {
            found = 1;
            break;
        }
    }
    printf("%s\n", found ? "YES" : "NO");
    return 0;
}
