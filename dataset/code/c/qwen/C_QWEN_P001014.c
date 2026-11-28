#include <stdio.h>
#include <stdlib.h>
int main() {
    int k, n; scanf("%d%d", &k, &n);
    int total = k*n;
    int a[total];
    for(int i=0; i<total; i++) scanf("%d", &a[i]);
    qsort(a, total, sizeof(int), cmp);
    for(int i=0; i<total; i++) printf("%d%c", a[i], i==total-1?'\n':' ');
    return 0;
}
