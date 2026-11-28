#include <stdio.h>
int main() {
    int n; scanf("%d", &n);
    int petrol[n], dist[n];
    for(int i=0; i<n; i++) scanf("%d", &petrol[i]);
    for(int i=0; i<n; i++) scanf("%d", &dist[i]);
    int start=0, end=1, curr=petrol[0]-dist[0];
    while(end!=start || curr<0) {
        while(curr<0 && start!=end) { curr-=petrol[start]-dist[start]; start=(start+1)%n; if(start==0) { printf("-1\n"); return 0; } }
        curr+=petrol[end]-dist[end]; end=(end+1)%n;
    }
    printf("%d\n", start);
    return 0;
}
