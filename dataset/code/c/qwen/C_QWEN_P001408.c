#include <stdio.h>
#include <stdlib.h>

int cmp(const void *a, const void *b) {
    return *(int *)a - *(int *)b;
}

int main() {
    int n;
    scanf("%d", &n);
    int nums[2 * n];
    for (int i = 0; i < 2 * n; i++) scanf("%d", &nums[i]);
    
    qsort(nums, 2 * n, sizeof(int), cmp);
    int k = -1;
    for (int i = 1; i < 2 * n; i++) {
        if ((nums[i] - nums[0]) % 2 == 0) {
            int cand_k = (nums[i] - nums[0]) / 2;
            if (cand_k > 0) {
                k = cand_k;
                break;
            }
        }
    }
    
    if (k == -1) {
        printf("-1\n");
        return 0;
    }
    
    int res[n];
    int idx = 0;
    int used[2 * n];
    for (int i = 0; i < 2 * n; i++) used[i] = 0;
    
    for (int i = 0; i < 2 * n; i++) {
        if (used[i]) continue;
        int target = nums[i] + 2 * k;
        int found = -1;
        for (int j = i + 1; j < 2 * n; j++) {
            if (!used[j] && nums[j] == target) {
                found = j;
                break;
            }
        }
        if (found == -1) {
            printf("-1\n");
            return 0;
        }
        res[idx++] = nums[i] + k;
        used[i] = 1;
        used[found] = 1;
    }
    
    for (int i = 0; i < n; i++) printf("%d ", res[i]);
    printf("\n");
    return 0;
}
