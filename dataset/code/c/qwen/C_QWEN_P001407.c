#include <stdio.h>
#include <stdlib.h>

int cmp(const void *a, const void *b) {
    return *(int *)a - *(int *)b;
}

int main() {
    int n;
    scanf("%d", &n);
    int nums[n];
    for (int i = 0; i < n; i++) scanf("%d", &nums[i]);
    
    if (n % 2 != 0) {
        printf("-1\n");
        return 0;
    }
    
    qsort(nums, n, sizeof(int), cmp);
    int res[n / 2];
    int idx = 0;
    int used[n];
    for (int i = 0; i < n; i++) used[i] = 0;
    
    for (int i = 0; i < n; i++) {
        if (used[i]) continue;
        int target = nums[i] * 2;
        int found = -1;
        for (int j = i + 1; j < n; j++) {
            if (!used[j] && nums[j] == target) {
                found = j;
                break;
            }
        }
        if (found == -1) {
            printf("-1\n");
            return 0;
        }
        res[idx++] = nums[i];
        used[i] = 1;
        used[found] = 1;
    }
    
    for (int i = 0; i < idx; i++) printf("%d ", res[i]);
    printf("\n");
    return 0;
}
