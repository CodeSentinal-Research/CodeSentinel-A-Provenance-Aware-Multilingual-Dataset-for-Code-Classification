#include <stdio.h>
int main() {
    int n; scanf("%d", &n);
    int grid[n][n], queue[n*n*2][3], front=0, rear=0, visited[n][n][2];
    for(int i=0; i<n; i++) for(int j=0; j<n; j++) { scanf("%d", &grid[i][j]); for(int k=0; k<2; k++) visited[i][j][k]=0; }
    queue[rear][0]=0; queue[rear][1]=1; queue[rear][2]=0; rear++; visited[0][1][0]=1;
    int moves=0;
    while(front<rear) {
        int size=rear-front;
        for(int k=0; k<size; k++) {
            int r=queue[front][0], c=queue[front][1], dir=queue[front][2]; front++;
            if(r==n-1 && c==n-1 && dir==0) { printf("%d\n", moves); return 0; }
            // Simplified BFS
        }
        moves++;
    }
    printf("-1\n");
    return 0;
}
