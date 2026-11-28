#include <stdio.h>
#include <stdlib.h>
int cmp(const void *a, const void *b) { return *(int*)a - *(int*)b; }
int main() {
    int n, k, target; scanf("%d %d %d", &n, &k, &target);
    int arr[n];
    for(int i=0; i<n; i++) scanf("%d", &arr[i]);
    int l=0, r=n-1;
    while(r-l+1 > k) {
        if(abs(arr[l]-target) > abs(arr[r]-target)) l++; else r--;
    }
    for(int i=l; i<=r; i++) printf("%d%c", arr[i], i==r?'\n':' ');
    return 0;
}
