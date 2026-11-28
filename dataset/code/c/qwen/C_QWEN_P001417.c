#include <stdio.h>
#include <stdlib.h>

int cmp(const void *a, const void *b) {
    return *(int *)a - *(int *)b;
}

int main() {
    int n, m;
    scanf("%d %d", &n, &m);
    int arr1[n], arr2[m];
    for (int i = 0; i < n; i++) scanf("%d", &arr1[i]);
    for (int i = 0; i < m; i++) scanf("%d", &arr2[i]);
    
    int count[1001] = {0};
    for (int i = 0; i < n; i++) count[arr1[i]]++;
    
    int idx = 0;
    for (int i = 0; i < m; i++) {
        while (count[arr2[i]] > 0) {
            arr1[idx++] = arr2[i];
            count[arr2[i]]--;
        }
    }
    
    int remaining[n - idx];
    int r_idx = 0;
    for (int i = 0; i <= 1000; i++) {
        while (count[i] > 0) {
            remaining[r_idx++] = i;
            count[i]--;
        }
    }
    
    qsort(remaining, r_idx, sizeof(int), cmp);
    for (int i = 0; i < r_idx; i++) arr1[idx++] = remaining[i];
    
    for (int i = 0; i < n; i++) printf("%d ", arr1[i]);
    printf("\n");
    return 0;
}
