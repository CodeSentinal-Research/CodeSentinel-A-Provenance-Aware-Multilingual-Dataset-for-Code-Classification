#include <stdio.h>

int main() {
    int n;
    scanf("%d", &n);
    int nums[n];
    int count[101] = {0};
    for (int i = 0; i < n; i++) {
        scanf("%d", &nums[i]);
        count[nums[i]]++;
    }
    
    int possible = 1;
    for (int i = 0; i <= 100; i++) {
        if (count[i] % 2 != 0) {
            possible = 0;
            break;
        }
    }
    printf("%s\n", possible ? "YES" : "NO");
    return 0;
}
