#include <stdio.h>
int main() {
    int n; scanf("%d", &n);
    int tree[2001], queue[2001], front=0, rear=0, level=0;
    for(int i=0; i<n; i++) scanf("%d", &tree[i]);
    if(n==0) { printf("[]\n"); return 0; }
    queue[rear++]=0;
    printf("[");
    while(front<rear) {
        int size=rear-front;
        printf("[");
        if(level%2==0) {
            for(int k=0; k<size; k++) { int curr=queue[front+k]; printf("%d%c", tree[curr], k==size-1?']':','); }
        } else {
            for(int k=size-1; k>=0; k--) { int curr=queue[front+k]; printf("%d%c", tree[curr], k==0?']':','); }
        }
        for(int k=0; k<size; k++) {
            int curr=queue[front++];
            int left=2*curr+1, right=2*curr+2;
            if(left<n && tree[left]!=-1) queue[rear++]=left;
            if(right<n && tree[right]!=-1) queue[rear++]=right;
        }
        if(front<rear) printf(",");
        level++;
    }
    printf("]\n");
    return 0;
}
