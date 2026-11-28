#include <stdio.h>
#include <stdlib.h>
int cmp(const void *a, const void *b) { return *(int*)b - *(int*)a; }
int main() {
    int q; scanf("%d", &q);
    int heap[200001], sz = 0;
    while(q--) {
        char op[10]; scanf("%s", op);
        if(op[0] == 'i') {
            int x; scanf("%d", &x);
            heap[sz++] = x;
            qsort(heap, sz, sizeof(int), cmp);
        } else if(op[0] == 'd') {
            if(sz > 0) sz--;
        } else {
            if(sz > 0) printf("%d\n", heap[0]);
        }
    }
    return 0;
}
