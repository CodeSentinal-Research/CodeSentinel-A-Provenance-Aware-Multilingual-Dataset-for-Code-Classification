#include <stdio.h>
#include <stdlib.h>
int cmp(const void *a, const void *b) { return *(int*)a - *(int*)b; }
int main() {
    int n, bricks, ladders; scanf("%d%d%d", &n, &bricks, &ladders);
    int h[n]; for(int i=0; i<n; i++) scanf("%d", &h[i]);
    int min_heap[100001], heap_size = 0;
    for(int i=0; i<n-1; i++) {
        int diff = h[i+1] - h[i];
        if(diff > 0) {
            min_heap[heap_size++] = diff;
            int p = heap_size - 1;
            while(p > 0 && min_heap[p] < min_heap[(p-1)/2]) { int t=min_heap[p]; min_heap[p]=min_heap[(p-1)/2]; min_heap[(p-1)/2]=t; p=(p-1)/2; }
            if(heap_size > ladders) {
                bricks -= min_heap[0];
                min_heap[0] = min_heap[--heap_size];
                int p = 0;
                while(2*p+1 < heap_size) {
                    int l = 2*p+1, r = 2*p+2, min_c = l;
                    if(r < heap_size && min_heap[r] < min_heap[l]) min_c = r;
                    if(min_heap[p] > min_heap[min_c]) { int t=min_heap[p]; min_heap[p]=min_heap[min_c]; min_heap[min_c]=t; p=min_c; }
                    else break;
                }
            }
            if(bricks < 0) { printf("%d\n", i); return 0; }
        }
    }
    printf("%d\n", n-1);
    return 0;
}
