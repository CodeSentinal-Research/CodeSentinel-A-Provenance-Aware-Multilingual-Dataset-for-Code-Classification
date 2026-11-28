#include <stdio.h>
#include <stdlib.h>
int cmp(const void *a, const void *b) { return *(int*)a - *(int*)b; }
int main() {
    int n, target; scanf("%d %d", &n, &target);
    int arr[n];
    for(int i=0; i<n; i++) scanf("%d", &arr[i]);
    qsort(arr, n, sizeof(int), cmp);
    int closest = arr[0] + arr[1] + arr[2];
    for(int i=0; i<n-2; i++) {
        int l = i+1, r = n-1;
        while(l < r) {
            int sum = arr[i] + arr[l] + arr[r];
            if(abs(sum - target) < abs(closest - target)) closest = sum;
            if(sum < target) l++; else r--;
        }
    }
    printf("%d\n", closest);
    return 0;
}
