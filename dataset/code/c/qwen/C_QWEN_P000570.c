#include <stdio.h>
int main() {
    int n, k; scanf("%d %d", &n, &k);
    int queue[n], front=0, rear=0;
    for(int i=0; i<n; i++) { scanf("%d", &queue[i]); rear++; }
    k=k%n;
    for(int i=0; i<k; i++) queue[rear++]=queue[front++];
    for(int i=front; i<rear; i++) printf("%d%c", queue[i], i==rear-1?'\n':' ');
    return 0;
}
