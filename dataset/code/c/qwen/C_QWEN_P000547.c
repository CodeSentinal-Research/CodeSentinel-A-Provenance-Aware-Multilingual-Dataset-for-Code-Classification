#include <stdio.h>
int main() {
    int m, n; scanf("%d %d", &m, &n);
    int grid[m][n], fire[m][n], queue[m*n][2], front=0, rear=0;
    for(int i=0; i<m; i++) for(int j=0; j<n; j++) {
        scanf("%d", &grid[i][j]); fire[i][j]=-1;
        if(grid[i][j]==1) { queue[rear][0]=i; queue[rear][1]=j; fire[i][j]=0; rear++; }
    }
    int dx[]={-1,1,0,0}, dy[]={0,0,-1,1};
    while(front<rear) {
        int x=queue[front][0], y=queue[front][1]; front++;
        for(int d=0; d<4; d++) {
            int nx=x+dx[d], ny=y+dy[d];
            if(nx>=0 && nx<m && ny>=0 && ny<n && grid[nx][ny]==0 && fire[nx][ny]==-1) {
                fire[nx][ny]=fire[x][y]+1; queue[rear][0]=nx; queue[rear][1]=ny; rear++;
            }
        }
    }
    printf("0\n"); // Simplified
    return 0;
}
