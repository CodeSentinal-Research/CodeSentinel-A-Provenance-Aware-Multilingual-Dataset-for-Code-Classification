#include <stdio.h>
#include <stdlib.h>
int cmp(const void *a, const void *b) { return *(int*)a - *(int*)b; }
int main() {
    int n, power; scanf("%d%d", &n, &power);
    int tokens[n]; for(int i=0; i<n; i++) scanf("%d", &tokens[i]);
    qsort(tokens, n, sizeof(int), cmp);
    int l=0, r=n-1, score=0, max_score=0;
    while(l <= r) {
        if(power >= tokens[l]) { power -= tokens[l++]; score++; if(score > max_score) max_score = score; }
        else if(score > 0) { power += tokens[r--]; score--; }
        else break;
    }
    printf("%d\n", max_score);
    return 0;
}
