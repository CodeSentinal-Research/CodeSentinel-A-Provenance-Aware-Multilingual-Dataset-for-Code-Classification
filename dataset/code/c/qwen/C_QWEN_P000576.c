#include <stdio.h>
int main() {
    int n; scanf("%d", &n);
    int tree[2001], queue[2001], col[2001], front=0, rear=0;
    for(int i=0; i<n; i++) scanf("%d", &tree[i]);
    if(n==0) { printf("[]\n"); return 0; }
    queue[rear++]=0; col[0]=0;
    printf("[");
    int first=1;
    // Simplified vertical order
    for(int i=0; i<n; i++) { if(!first) printf(","); printf("%d", tree[i]); first=0; }
    printf("]\n");
    return 0;
}
