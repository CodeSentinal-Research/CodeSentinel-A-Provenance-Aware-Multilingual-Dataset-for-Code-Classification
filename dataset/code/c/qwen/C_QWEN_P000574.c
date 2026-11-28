#include <stdio.h>
int main() {
    int n; scanf("%d", &n);
    int tree[2001], queue[2001], front=0, rear=0;
    for(int i=0; i<n; i++) scanf("%d", &tree[i]);
    if(n==0) { printf("[]\n"); return 0; }
    queue[rear++]=0;
    printf("[");
    int first=1;
    while(front<rear) {
        int size=rear-front;
        int last_val=tree[queue[front+size-1]];
        if(!first) printf(",");
        printf("%d", last_val); first=0;
        for(int k=0; k<size; k++) {
            int curr=queue[front++];
            int left=2*curr+1, right=2*curr+2;
            if(left<n && tree[left]!=-1) queue[rear++]=left;
            if(right<n && tree[right]!=-1) queue[rear++]=right;
        }
    }
    printf("]\n");
    return 0;
}
