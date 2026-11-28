#include <stdio.h>
int main() {
    int n; scanf("%d", &n);
    int board[n][n], queue[n*n][2], front=0, rear=0, visited[n*n+1]={0};
    for(int i=0; i<n; i++) for(int j=0; j<n; j++) scanf("%d", &board[i][j]);
    queue[rear][0]=1; queue[rear][1]=0; rear++; visited[1]=1;
    while(front<rear) {
        int curr=queue[front][0], moves=queue[front][1]; front++;
        if(curr==n*n) { printf("%d\n", moves); return 0; }
        for(int i=1; i<=6; i++) {
            int next=curr+i;
            if(next>n*n) break;
            int r=(next-1)/n, c=(next-1)%n;
            if(r%2==1) c=n-1-c;
            int actual=board[n-1-r][c]!=-1 ? board[n-1-r][c] : next;
            if(!visited[actual]) { visited[actual]=1; queue[rear][0]=actual; queue[rear][1]=moves+1; rear++; }
        }
    }
    printf("-1\n");
    return 0;
}
