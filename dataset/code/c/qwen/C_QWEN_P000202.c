#include <stdio.h>
#include <stdlib.h>
int cmp(const void *a, const void *b) { return *(int*)a - *(int*)b; }
int main() {
    int n; scanf("%d", &n);
    int arr[n];
    for(int i=0; i<n; i++) scanf("%d", &arr[i]);
    qsort(arr, n, sizeof(int), cmp);
    int max_len = 1, cur = 1;
    for(int i=1; i<n; i++) {
        if(arr[i] == arr[i-1] + 1) cur++;
        else if(arr[i] != arr[i-1]) cur = 1;
        if(cur > max_len) max_len = cur;
    }
    printf("%d\n", max_len);
    return 0;
}
