#include <stdio.h>
#include <stdlib.h>

int cmp(const void* a, const void* b) {
    return (*(int*)a - *(int*)b);
}

int main() {
    int n, k;
    if (scanf("%d %d", &n, &k) == 2 && n > 0) {
        int arr[n];
        for (int i = 0; i < n; i++) scanf("%d", &arr[i]);
        qsort(arr, n, sizeof(int), cmp);

        int dups[n];
        int dSize = 0;
        int unique = 0;
        int i = 0;
        while (i < n) {
            int val = arr[i];
            int cnt = 0;
            while (i < n && arr[i] == val) { cnt++; i++; }
            unique++;
            if (cnt > 1) dups[dSize++] = cnt - 1;
        }
        qsort(dups, dSize, sizeof(int), cmp);

        for (int j = 0; j < dSize && k > 0; j++) {
            if (k >= dups[j]) {
                k -= dups[j];
            } else {
                k = 0;
            }
        }
        if (k > 0) unique -= k;
        if (unique < 0) unique = 0;
        printf("%d\n", unique);
    }
    return 0;
}