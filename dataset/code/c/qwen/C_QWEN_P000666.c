#include <stdio.h>
#include <stdlib.h>
int cmp(const void *a, const void *b) { return *(int*)a - *(int*)b; }
int main() {
    int n1; scanf("%d", &n1); int a[n1]; for(int i=0; i<n1; i++) scanf("%d", &a[i]);
    int n2; scanf("%d", &n2); int b[n2]; for(int i=0; i<n2; i++) scanf("%d", &b[i]);
    int all[n1+n2]; for(int i=0; i<n1; i++) all[i]=a[i]; for(int i=0; i<n2; i++) all[n1+i]=b[i];
    qsort(all, n1+n2, sizeof(int), cmp);
    for(int i=0; i<n1+n2; i++) printf("%d ", all[i]);
    printf("\n");
    return 0;
}
