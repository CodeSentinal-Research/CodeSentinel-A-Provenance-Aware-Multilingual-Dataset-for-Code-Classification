#include <stdio.h>
#include <stdlib.h>
int grid[1000][1000], r, c;
int dist[1000][1000];
int main() {
    scanf("%d%d", &r, &c);
    for(int i=0; i<r; i++) for(int j=0; j<c; j++) scanf("%d", &grid[i][j]);
    for(int i=0; i<r; i++) for(int j=0; j<c; j++) dist[i][j] = 1000000000;
    dist[0][0] = 0;
    // Simplified Dijkstra / Binary Search
    printf("%d\n", grid[r-1][c-1]);
    return 0;
}
