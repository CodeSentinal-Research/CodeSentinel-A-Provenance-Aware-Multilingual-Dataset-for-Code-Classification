#include <stdio.h>
int main() {
    int n, k; scanf("%d %d", &n, &k);
    int queue[100001], front=0, rear=0;
    for(int i=1; i<=n; i++) queue[rear++]=i;
    while(rear-front>1) {
        for(int i=0; i<k-1; i++) queue[rear++]=queue[front++];
        front++;
    }
    printf("%d\n", queue[front]);
    return 0;
}
