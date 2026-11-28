#include <stdio.h>

int main() {
    int n;
    scanf("%d", &n);
    int nums[n];
    for (int i = 0; i < n; i++) scanf("%d", &nums[i]);
    
    int pos[n], neg[n], p = 0, ng = 0;
    for (int i = 0; i < n; i++) {
        if (nums[i] > 0) pos[p++] = nums[i];
        else neg[ng++] = nums[i];
    }
    for (int i = 0; i < p; i++) printf("%d ", pos[i]);
    for (int i = 0; i < ng; i++) printf("%d ", neg[i]);
    printf("\n");
    return 0;
}
