#include <stdio.h>
#include <stdlib.h>
int main() {
    int n; scanf("%d", &n);
    int h[n]; for(int i=0; i<n; i++) scanf("%d", &h[i]);
    int bricks, ladders; scanf("%d%d", &bricks, &ladders);
    int diffs[n];
    for(int i=0; i<n-1; i++) diffs[i] = h[i+1] > h[i] ? h[i+1] - h[i] : 0;
    qsort(diffs, n-1, sizeof(int), cmp);
    int idx = 0;
    for(int i=0; i<n-1; i++) {
        if(diffs[i] > 0) {
            if(ladders > 0) ladders--;
            else if(bricks >= diffs[i]) bricks -= diffs[i];
            else { idx = i; break; }
        }
    }
    printf("%d\n", idx);
    return 0;
}
