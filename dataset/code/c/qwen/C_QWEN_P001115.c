#include <stdio.h>
int grid[1000][1000], n;
int queue[1000000][3], front=0, rear=0;
int main() {
    scanf("%d", &n);
    for(int i=0; i<n; i++) for(int j=0; j<n; j++) scanf("%d", &grid[i][j]);
    if(grid[0][0] != 0 || grid[n-1][n-1] != 0) { printf("-1\n"); return 0; }
    queue[rear][0]=0; queue[rear][1]=0; queue[rear++][2]=1;
    grid[0][0] = 1;
    int dx[]={-1,1,0,0,-1,-1,1,1}, dy[]={0,0,-1,1,-1,1,-1,1};
    while(front < rear) {
        int x=queue[front][0], y=queue[front][1], d=queue[front++][2];
        if(x==n-1 && y==n-1) { printf("%d\n", d); return 0; }
        for(int i=0; i<8; i++) {
            int nx=x+dx[i], ny=y+dy[i];
            if(nx>=0 && nx<n && ny>=0 && ny<n && grid[nx][ny] == 0) {
                grid[nx][ny] = 1; queue[rear][0]=nx; queue[rear][1]=ny; queue[rear++][2]=d+1;
            }
        }
    }
    printf("-1\n");
    return 0;
}
