#include <stdio.h>
int main() {
    int n, k; scanf("%d %d", &n, &k);
    int queue[n], stack[n], top=-1, front=0, rear=0;
    for(int i=0; i<n; i++) { scanf("%d", &queue[i]); rear++; }
    for(int i=0; i<k; i++) stack[++top]=queue[front++];
    while(top>=0) { queue[rear++]=stack[top--]; }
    for(int i=front; i<rear; i++) printf("%d%c", queue[i], i==rear-1?'\n':' ');
    return 0;
}
