#include <stdio.h>
#include <stdlib.h>
int cmp(const void *a, const void *b) { return *(int*)a - *(int*)b; }
int main() {
    int n, m; long long success;
    scanf("%d %d %lld", &n, &m, &success);
    int spells[n], potions[m];
    for(int i=0; i<n; i++) scanf("%d", &spells[i]);
    for(int i=0; i<m; i++) scanf("%d", &potions[i]);
    qsort(potions, m, sizeof(int), cmp);
    for(int i=0; i<n; i++) {
        long long min_potion = (success + spells[i] - 1) / spells[i];
        int l=0, r=m, ans=m;
        while(l<r) {
            int mid = l + (r-l)/2;
            if(potions[mid] >= min_potion) { ans = mid; r=mid; }
            else l=mid+1;
        }
        printf("%d ", m - ans);
    }
    printf("\n");
    return 0;
}
