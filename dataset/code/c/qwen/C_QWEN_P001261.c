#include <stdio.h>
#include <stdlib.h>
int cmp(const void *a, const void *b) { return *(int*)a - *(int*)b; }
int main() {
    int target, startFuel; scanf("%d%d", &target, &startFuel);
    int n; scanf("%d", &n);
    int pos[n], fuel[n];
    for(int i=0; i<n; i++) scanf("%d%d", &pos[i], &fuel[i]);
    int max_heap[100001], heap_size = 0;
    int stops = 0, curr_fuel = startFuel, prev_pos = 0;
    for(int i=0; i<=n; i++) {
        int dist = (i == n ? target : pos[i]) - prev_pos;
        curr_fuel -= dist;
        while(curr_fuel < 0 && heap_size > 0) {
            // pop max
            int max_f = max_heap[0];
            max_heap[0] = max_heap[--heap_size];
            int p = 0;
            while(2*p+1 < heap_size) {
                int l = 2*p+1, r = 2*p+2, max_c = l;
                if(r < heap_size && max_heap[r] > max_heap[l]) max_c = r;
                if(max_heap[p] < max_heap[max_c]) { int t=max_heap[p]; max_heap[p]=max_heap[max_c]; max_heap[max_c]=t; p=max_c; }
                else break;
            }
            curr_fuel += max_f;
            stops++;
        }
        if(curr_fuel < 0) { printf("-1\n"); return 0; }
        if(i < n) {
            max_heap[heap_size++] = fuel[i];
            int p = heap_size - 1;
            while(p > 0 && max_heap[p] > max_heap[(p-1)/2]) { int t=max_heap[p]; max_heap[p]=max_heap[(p-1)/2]; max_heap[(p-1)/2]=t; p=(p-1)/2; }
        }
        prev_pos = (i == n ? target : pos[i]);
    }
    printf("%d\n", stops);
    return 0;
}
