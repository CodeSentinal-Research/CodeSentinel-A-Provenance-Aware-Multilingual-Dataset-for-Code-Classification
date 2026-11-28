#include <stdio.h>
#include <stdlib.h>
struct Course { int d, l; };
int cmp(const void *a, const void *b) { return ((struct Course*)a)->l - ((struct Course*)b)->l; }
int main() {
    int n; scanf("%d", &n);
    struct Course c[n]; for(int i=0; i<n; i++) scanf("%d%d", &c[i].d, &c[i].l);
    qsort(c, n, sizeof(struct Course), cmp);
    int max_heap[200001], heap_size = 0;
    int time = 0, count = 0;
    for(int i=0; i<n; i++) {
        if(time + c[i].d <= c[i].l) {
            time += c[i].d;
            max_heap[heap_size++] = c[i].d;
            int p = heap_size - 1;
            while(p > 0 && max_heap[p] > max_heap[(p-1)/2]) { int t=max_heap[p]; max_heap[p]=max_heap[(p-1)/2]; max_heap[(p-1)/2]=t; p=(p-1)/2; }
            count++;
        } else if(heap_size > 0 && max_heap[0] > c[i].d) {
            time -= max_heap[0];
            max_heap[0] = c[i].d;
            time += c[i].d;
            int p = 0;
            while(2*p+1 < heap_size) {
                int l = 2*p+1, r = 2*p+2, max_c = l;
                if(r < heap_size && max_heap[r] > max_heap[l]) max_c = r;
                if(max_heap[p] < max_heap[max_c]) { int t=max_heap[p]; max_heap[p]=max_heap[max_c]; max_heap[max_c]=t; p=max_c; }
                else break;
            }
        }
    }
    printf("%d\n", count);
    return 0;
}
