#include <stdio.h>
#include <stdlib.h>
struct Eng { int spd, eff; };
int cmp(const void *a, const void *b) { return ((struct Eng*)b)->eff - ((struct Eng*)a)->eff; }
int main() {
    int n, k; scanf("%d%d", &n, &k);
    struct Eng e[n];
    for(int i=0; i<n; i++) scanf("%d", &e[i].spd);
    for(int i=0; i<n; i++) scanf("%d", &e[i].eff);
    qsort(e, n, sizeof(struct Eng), cmp);
    long long sum_spd = 0, max_perf = 0;
    int min_heap[100001], heap_size = 0;
    for(int i=0; i<n; i++) {
        sum_spd += e[i].spd;
        min_heap[heap_size++] = e[i].spd;
        int p = heap_size - 1;
        while(p > 0 && min_heap[p] < min_heap[(p-1)/2]) { int t=min_heap[p]; min_heap[p]=min_heap[(p-1)/2]; min_heap[(p-1)/2]=t; p=(p-1)/2; }
        if(heap_size > k) {
            sum_spd -= min_heap[0];
            min_heap[0] = min_heap[--heap_size];
            int p = 0;
            while(2*p+1 < heap_size) {
                int l = 2*p+1, r = 2*p+2, min_c = l;
                if(r < heap_size && min_heap[r] < min_heap[l]) min_c = r;
                if(min_heap[p] > min_heap[min_c]) { int t=min_heap[p]; min_heap[p]=min_heap[min_c]; min_heap[min_c]=t; p=min_c; }
                else break;
            }
        }
        long long perf = sum_spd * e[i].eff;
        if(perf > max_perf) max_perf = perf;
    }
    printf("%lld\n", max_perf);
    return 0;
}
