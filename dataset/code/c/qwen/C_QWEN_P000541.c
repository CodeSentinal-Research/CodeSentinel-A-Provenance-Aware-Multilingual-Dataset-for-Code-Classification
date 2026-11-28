#include <stdio.h>
int main() {
    int m, n; scanf("%d %d", &m, &n);
    int grid[m][n], queue[m*n][2], front=0, rear=0, fresh=0;
    for(int i=0; i<m; i++) for(int j=0; j<n; j++) {
        scanf("%d", &grid[i][j]);
        if(grid[i][j]==2) { queue[rear][0]=i; queue[rear][1]=j; rear++; }
        else if(grid[i][j]==1) fresh++;
    }
    int mins=0;
    int dx[]={-1,1,0,0}, dy[]={0,0,-1,1};
    while(front<rear && fresh>0) {
        int size=rear-front;
        for(int k=0; k<size; k++) {
            int x=queue[front][0], y=queue[front][1]; front++;
            for(int d=0; d<4; d++) {
                int nx=x+dx[d], ny=y+dy[d];
                if(nx>=0 && nx<m && ny>=0 && ny<n && grid[nx][ny]==1) {
                    grid[nx][ny]=2; fresh--; queue[rear][0]=nx; queue[rear][1]=ny; rear++;
                }
            }
        }
        mins++;
    }
    printf("%d\n", fresh==0 ? mins : -1);
    return 0;
}
