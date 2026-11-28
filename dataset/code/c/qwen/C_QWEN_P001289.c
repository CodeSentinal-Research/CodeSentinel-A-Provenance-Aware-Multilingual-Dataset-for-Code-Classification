#include <stdio.h>
#include <stdlib.h>
int cmp(const void *a, const void *b) { return *(int*)a - *(int*)b; }
int main() {
    int n; scanf("%d", &n);
    int a[n]; for(int i=0; i<n; i++) scanf("%d", &a[i]);
    qsort(a, n, sizeof(int), cmp);
    int max_sum = 0;
    for(int i=0; i<n/2; i++) {
        int sum = a[i] + a[n-1-i];
        if(sum > max_sum) max_sum = sum;
    }
    printf("%d\n", max_sum);
    return 0;
}
