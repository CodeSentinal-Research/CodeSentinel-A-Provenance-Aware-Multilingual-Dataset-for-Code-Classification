#include <stdio.h>
int main() {
    int n, p, b, k; scanf("%d %d %d %d", &n, &p, &b, &k);
    int banned[b]; for(int i=0; i<b; i++) scanf("%d", &banned[i]);
    int queue[n], front=0, rear=0, visited[n], dist[n];
    for(int i=0; i<n; i++) { visited[i]=0; dist[i]=-1; }
    queue[rear++]=p; visited[p]=1; dist[p]=0;
    while(front<rear) {
        int curr=queue[front++];
        for(int i=1; i<=k; i++) {
            int next=curr+i; if(next<n && !visited[next]) { visited[next]=1; dist[next]=dist[curr]+1; queue[rear++]=next; }
            next=curr-i; if(next>=0 && !visited[next]) { visited[next]=1; dist[next]=dist[curr]+1; queue[rear++]=next; }
        }
    }
    for(int i=0; i<n; i++) printf("%d%c", dist[i], i==n-1?'\n':' ');
    return 0;
}
