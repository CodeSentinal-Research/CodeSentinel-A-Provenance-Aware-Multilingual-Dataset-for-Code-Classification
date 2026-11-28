#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#define MAX_N 1005
int arr[MAX_N];
int cmp(const void* a, const void* b) { return (*(int*)a - *(int*)b); }
int main() {
    int n, target;
    if (scanf("%d %d", &n, &target) == 2) {
        for (int i = 0; i < n; i++) scanf("%d", &arr[i]);
        qsort(arr, n, sizeof(int), cmp);
        bool found = false;
        for (int i = 0; i < n - 2; i++) {
            int l = i + 1, r = n - 1;
            while (l < r) {
                int s = arr[i] + arr[l] + arr[r];
                if (s == target) { found = true; break; }
                else if (s < target) l++;
                else r--;
            }
            if (found) break;
        }
        printf("%s\n", found ? "Yes" : "No");
    }
    return 0;
}