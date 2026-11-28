#include <stdio.h>
#include <stdlib.h>

int cmpIntDiff(const void* a, const void* b) {
    return (*(int*)a - *(int*)b);
}

int main() {
    int n, k;
    if (scanf("%d %d", &n, &k) == 2) {
        int* arr = (int*)malloc(n * sizeof(int));
        for (int i = 0; i < n; i++) scanf("%d", &arr[i]);

        qsort(arr, n, sizeof(int), cmpIntDiff);

        int ans = 0;
        int l = 0, r = 0;

        while (r < n) {
            if (r <= l) { r++; continue; }
            int diff = arr[r] - arr[l];
            if (diff == k) {
                ans++;
                int prevL = arr[l];
                while (l < n && arr[l] == prevL) l++;
                while (r < n && arr[r] == arr[r - 1]) r++;
            } else if (diff < k) {
                r++;
            } else {
                l++;
            }
        }
        printf("%d\n", ans);
        free(arr);
    }
    return 0;
}