#include <stdio.h>
int grid[1000][1000], r, c;
int queue[1000000][3], front=0, rear=0;
int main() {
    scanf("%d%d", &r, &c);
    int fresh = 0;
    for(int i=0; i<r; i++) for(int j=0; j<c; j++) {
        scanf("%d", &grid[i][j]);
        if(grid[i][j] == 2) { queue[rear][0]=i; queue[rear][1]=j; queue[rear++][2]=0; }
        else if(grid[i][j] == 1) fresh++;
    }
    int mins = 0;
    int dx[]={-1,1,0,0}, dy[]={0,0,-1,1};
    while(front < rear) {
        int x=queue[front][0], y=queue[front][1], t=queue[front++][2];
        mins = t;
        for(int d=0; d<4; d++) {
            int nx=x+dx[d], ny=y+dy[d];
            if(nx>=0 && nx<r && ny>=0 && ny<c && grid[nx][ny] == 1) {
                grid[nx][ny] = 2; fresh--; queue[rear][0]=nx; queue[rear][1]=ny; queue[rear++][2]=t+1;
            }
        }
    }
    printf("%d\n", fresh == 0 ? mins : -1);
    return 0;
}
