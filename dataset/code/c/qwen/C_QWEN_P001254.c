#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int cmp(const void *a, const void *b) {
    char s1[20], s2[20];
    sprintf(s1, "%d%d", *(int*)b, *(int*)a);
    sprintf(s2, "%d%d", *(int*)a, *(int*)b);
    return strcmp(s1, s2);
}
int main() {
    int n; scanf("%d", &n);
    int a[n]; for(int i=0; i<n; i++) scanf("%d", &a[i]);
    qsort(a, n, sizeof(int), cmp);
    if(a[0] == 0) printf("0\n");
    else for(int i=0; i<n; i++) printf("%d", a[i]);
    printf("\n");
    return 0;
}
