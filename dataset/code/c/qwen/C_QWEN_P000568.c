#include <stdio.h>
#include <math.h>
int main() {
    int x, y; scanf("%d %d", &x, &y);
    x=abs(x); y=abs(y);
    int queue[100001][3], front=0, rear=0, visited[601][601];
    for(int i=0; i<=600; i++) for(int j=0; j<=600; j++) visited[i][j]=0;
    queue[rear][0]=0; queue[rear][1]=0; queue[rear][2]=0; rear++; visited[0][0]=1;
    int dx[]={-2,-2,-1,-1,1,1,2,2}, dy[]={-1,1,-2,2,-2,2,-1,1};
    while(front<rear) {
        int cx=queue[front][0], cy=queue[front][1], steps=queue[front][2]; front++;
        if(cx==x && cy==y) { printf("%d\n", steps); return 0; }
        for(int d=0; d<8; d++) {
            int nx=cx+dx[d], ny=cy+dy[d];
            if(nx>=-300 && nx<=300 && ny>=-300 && ny<=300 && !visited[nx+300][ny+300]) {
                visited[nx+300][ny+300]=1; queue[rear][0]=nx; queue[rear][1]=ny; queue[rear][2]=steps+1; rear++;
            }
        }
    }
    return 0;
}
