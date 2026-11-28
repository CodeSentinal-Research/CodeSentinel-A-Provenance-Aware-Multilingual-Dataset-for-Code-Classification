#include <stdio.h>
int main() {
    int m, n, er, ec; scanf("%d %d %d %d", &m, &n, &er, &ec);
    char grid[m][n+1]; int queue[m*n][3], front=0, rear=0, visited[m][n];
    for(int i=0; i<m; i++) for(int j=0; j<n; j++) { scanf("%s", grid[i]); visited[i][j]=0; }
    queue[rear][0]=er; queue[rear][1]=ec; queue[rear][2]=0; rear++; visited[er][ec]=1;
    int dx[]={-1,1,0,0}, dy[]={0,0,-1,1};
    while(front<rear) {
        int x=queue[front][0], y=queue[front][1], moves=queue[front][2]; front++;
        if((x==0 || x==m-1 || y==0 || y==n-1) && !(x==er && y==ec)) { printf("%d\n", moves); return 0; }
        for(int d=0; d<4; d++) {
            int nx=x+dx[d], ny=y+dy[d];
            if(nx>=0 && nx<m && ny>=0 && ny<n && grid[nx][ny]=='.' && !visited[nx][ny]) {
                visited[nx][ny]=1; queue[rear][0]=nx; queue[rear][1]=ny; queue[rear][2]=moves+1; rear++;
            }
        }
    }
    printf("-1\n");
    return 0;
}
