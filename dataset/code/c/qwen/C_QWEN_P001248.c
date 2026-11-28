#include <stdio.h>
#include <stdlib.h>
int cmp(const void *a, const void *b) { return *(int*)a - *(int*)b; }
int main() {
    int n, limit; scanf("%d%d", &n, &limit);
    int w[n]; for(int i=0; i<n; i++) scanf("%d", &w[i]);
    qsort(w, n, sizeof(int), cmp);
    int l=0, r=n-1, boats=0;
    while(l <= r) {
        if(l == r) { boats++; break; }
        if(w[l] + w[r] <= limit) { l++; r--; }
        else r--;
        boats++;
    }
    printf("%d\n", boats);
    return 0;
}
