#include <stdio.h>
#include <stdlib.h>
int cmp(const void *a, const void *b) { return *(int*)a - *(int*)b; }
int main() {
    int n; scanf("%d", &n);
    int arr[n];
    for(int i=0; i<n; i++) scanf("%d", &arr[i]);
    qsort(arr, n, sizeof(int), cmp);
    int cont = 1;
    for(int i=1; i<n; i++) if(arr[i] - arr[i-1] > 1) { cont = 0; break; }
    printf("%s\n", cont ? "Yes" : "No");
    return 0;
}
