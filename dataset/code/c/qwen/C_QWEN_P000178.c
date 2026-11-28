#include <stdio.h>
#include <stdlib.h>
int arr[1001], count[2000001];
int cmp(const void *a, const void *b) {
    int ca = count[*(int*)a+1000000], cb = count[*(int*)b+1000000];
    if(ca != cb) return cb - ca;
    return *(int*)a - *(int*)b;
}
int main() {
    int n; scanf("%d", &n);
    for(int i=0; i<n; i++) { scanf("%d", &arr[i]); count[arr[i]+1000000]++; }
    qsort(arr, n, sizeof(int), cmp);
    for(int i=0; i<n; i++) printf("%d%c", arr[i], i==n-1?'\n':' ');
    return 0;
}
