#include <stdio.h>
#include <stdlib.h>
struct Interval { int start, end; };
int cmp(const void *a, const void *b) { return ((struct Interval*)a)->start - ((struct Interval*)b)->start; }
int main() {
    int n, carpet; scanf("%d %d", &n, &carpet);
    struct Interval tiles[n];
    for(int i=0; i<n; i++) scanf("%d %d", &tiles[i].start, &tiles[i].end);
    qsort(tiles, n, sizeof(struct Interval), cmp);
    long long max_cover = 0, cur_cover = 0;
    int l = 0;
    for(int r=0; r<n; r++) {
        cur_cover += tiles[r].end - tiles[r].start + 1;
        while(tiles[r].end - tiles[l].start + 1 > carpet) {
            cur_cover -= tiles[l].end - tiles[l].start + 1;
            l++;
        }
        if(cur_cover > max_cover) max_cover = cur_cover;
    }
    printf("%lld\n", max_cover);
    return 0;
}
