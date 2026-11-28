#include <stdio.h>
#include <stdlib.h>
int cmp(const void *a, const void *b) { return *(int*)a - *(int*)b; }
int main() {
    int n, k; scanf("%d%d", &n, &k);
    int a[n]; for(int i=0; i<n; i++) scanf("%d", &a[i]);
    int count[100001] = {0};
    for(int i=0; i<n; i++) count[a[i]]++;
    int freq[n]; int sz = 0;
    for(int i=0; i<=100000; i++) if(count[i]) freq[sz++] = count[i];
    qsort(freq, sz, sizeof(int), cmp);
    int distinct = sz;
    for(int i=0; i<sz && k > 0; i++) {
        if(freq[i] <= k) { k -= freq[i]; distinct--; }
        else break;
    }
    printf("%d\n", distinct);
    return 0;
}
