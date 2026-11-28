#include <stdio.h>
#include <stdlib.h>
int main() {
    int q; scanf("%d", &q);
    int heap[200001], sz = 0;
    int next = 1;
    while(q--) {
        char op[10]; scanf("%s", op);
        if(op[0] == 'a') {
            int x; scanf("%d", &x);
            heap[sz++] = x;
            qsort(heap, sz, sizeof(int), cmp);
        } else {
            if(sz > 0) { printf("%d\n", heap[0]); for(int i=0; i<sz-1; i++) heap[i] = heap[i+1]; sz--; }
            else { printf("%d\n", next); next++; }
        }
    }
    return 0;
}
