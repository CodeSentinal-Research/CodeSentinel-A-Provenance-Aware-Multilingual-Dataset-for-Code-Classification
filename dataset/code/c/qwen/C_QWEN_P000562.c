#include <stdio.h>
int main() {
    int n; scanf("%d", &n);
    int rooms[n][100], sizes[n], queue[1001], front=0, rear=0, visited[1001]={0};
    for(int i=0; i<n; i++) {
        scanf("%d", &sizes[i]);
        for(int j=0; j<sizes[i]; j++) scanf("%d", &rooms[i][j]);
    }
    queue[rear++]=0; visited[0]=1; int count=1;
    while(front<rear) {
        int curr=queue[front++];
        for(int i=0; i<sizes[curr]; i++) {
            int next=rooms[curr][i];
            if(!visited[next]) { visited[next]=1; queue[rear++]=next; count++; }
        }
    }
    printf("%s\n", count==n ? "true" : "false");
    return 0;
}
