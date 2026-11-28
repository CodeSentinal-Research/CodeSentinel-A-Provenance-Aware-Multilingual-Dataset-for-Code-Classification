#include <stdio.h>
#include <stdlib.h>
int cmp(const void *a, const void *b) { return *(int*)a - *(int*)b; }
int main() {
    int n; scanf("%d", &n);
    int a[n]; for(int i=0; i<n; i++) scanf("%d", &a[i]);
    for(int i=0; i<n; i++) if(a[i] % 2 != 0) a[i] *= 2;
    qsort(a, n, sizeof(int), cmp);
    int min_dev = a[n-1] - a[0];
    while(a[n-1] % 2 == 0) {
        a[n-1] /= 2;
        qsort(a, n, sizeof(int), cmp);
        int dev = a[n-1] - a[0];
        if(dev < min_dev) min_dev = dev;
    }
    printf("%d\n", min_dev);
    return 0;
}
