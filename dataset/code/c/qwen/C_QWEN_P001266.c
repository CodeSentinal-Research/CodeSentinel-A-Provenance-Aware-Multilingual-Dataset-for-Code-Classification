#include <stdio.h>
#include <stdlib.h>
struct Proj { int cap, prof; };
int cmp_cap(const void *a, const void *b) { return ((struct Proj*)a)->cap - ((struct Proj*)b)->cap; }
int cmp_prof(const void *a, const void *b) { return ((struct Proj*)b)->prof - ((struct Proj*)a)->prof; }
int main() {
    int n, k; long long capital; scanf("%d%d%lld", &n, &k, &capital);
    struct Proj p[n];
    for(int i=0; i<n; i++) scanf("%d%d", &p[i].cap, &p[i].prof);
    qsort(p, n, sizeof(struct Proj), cmp_cap);
    int idx = 0;
    int max_heap[100001], heap_size = 0;
    for(int i=0; i<k; i++) {
        while(idx < n && p[idx].cap <= capital) {
            max_heap[heap_size++] = p[idx].prof;
            int p_idx = heap_size - 1;
            while(p_idx > 0 && max_heap[p_idx] > max_heap[(p_idx-1)/2]) { int t=max_heap[p_idx]; max_heap[p_idx]=max_heap[(p_idx-1)/2]; max_heap[(p_idx-1)/2]=t; p_idx=(p_idx-1)/2; }
            idx++;
        }
        if(heap_size == 0) break;
        capital += max_heap[0];
        max_heap[0] = max_heap[--heap_size];
        int p_idx = 0;
        while(2*p_idx+1 < heap_size) {
            int l = 2*p_idx+1, r = 2*p_idx+2, max_c = l;
            if(r < heap_size && max_heap[r] > max_heap[l]) max_c = r;
            if(max_heap[p_idx] < max_heap[max_c]) { int t=max_heap[p_idx]; max_heap[p_idx]=max_heap[max_c]; max_heap[max_c]=t; p_idx=max_c; }
            else break;
        }
    }
    printf("%lld\n", capital);
    return 0;
}
