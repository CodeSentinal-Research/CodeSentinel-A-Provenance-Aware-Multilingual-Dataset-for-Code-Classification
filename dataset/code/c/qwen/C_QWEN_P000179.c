#include <stdio.h>
#include <stdlib.h>
int arr1[1001], arr2[1001], res[1001];
int cmp(const void *a, const void *b) { return *(int*)a - *(int*)b; }
int main() {
    int m, n; scanf("%d %d", &m, &n);
    for(int i=0; i<m; i++) scanf("%d", &arr1[i]);
    for(int i=0; i<n; i++) scanf("%d", &arr2[i]);
    int idx = 0, count[1001] = {0};
    for(int i=0; i<m; i++) count[arr1[i]]++;
    for(int i=0; i<n; i++) {
        while(count[arr2[i]] > 0) { res[idx++] = arr2[i]; count[arr2[i]]--; }
    }
    int temp[1001], t_idx = 0;
    for(int i=0; i<1001; i++) while(count[i] > 0) { temp[t_idx++] = i; count[i]--; }
    qsort(temp, t_idx, sizeof(int), cmp);
    for(int i=0; i<t_idx; i++) res[idx++] = temp[i];
    for(int i=0; i<idx; i++) printf("%d%c", res[i], i==idx-1?'\n':' ');
    return 0;
}
