#include <stdio.h>
#include <stdlib.h>
int cmp(const void *a, const void *b) { return *(int*)a - *(int*)b; }
int main() {
    int n; scanf("%d", &n);
    int deck[n], res[n], queue[n], front=0, rear=0;
    for(int i=0; i<n; i++) scanf("%d", &deck[i]);
    qsort(deck, n, sizeof(int), cmp);
    for(int i=0; i<n; i++) queue[rear++]=i;
    for(int i=0; i<n; i++) {
        res[queue[front++]]=deck[i];
        if(front<rear) { queue[rear++]=queue[front++]; }
    }
    for(int i=0; i<n; i++) printf("%d%c", res[i], i==n-1?'\n':' ');
    return 0;
}
