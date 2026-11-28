#include <stdio.h>
int main() {
    int m, n; scanf("%d %d", &m, &n);
    int grid[m][n], queue[m*n][3], front=0, rear=0, visited[m][n];
    for(int i=0; i<m; i++) for(int j=0; j<n; j++) { scanf("%d", &grid[i][j]); visited[i][j]=0; }
    queue[rear][0]=0; queue[rear][1]=0; queue[rear][2]=1; rear++; visited[0][0]=1;
    while(front<rear) {
        int x=queue[front][0], y=queue[front][1], steps=queue[front][2]; front++;
        if(x==m-1 && y==n-1) { printf("%d\n", steps); return 0; }
        int max_move=grid[x][y];
        for(int i=1; i<=max_move; i++) {
            if(y+i<n && !visited[x][y+i]) { visited[x][y+i]=1; queue[rear][0]=x; queue[rear][1]=y+i; queue[rear][2]=steps+1; rear++; }
            if(x+i<m && !visited[x+i][y]) { visited[x+i][y]=1; queue[rear][0]=x+i; queue[rear][1]=y; queue[rear][2]=steps+1; rear++; }
        }
    }
    printf("-1\n");
    return 0;
}
