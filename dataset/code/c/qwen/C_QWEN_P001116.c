#include <stdio.h>
char grid[1000][1001];
int r, c;
void dfs(int i, int j) {
    if(i<0 || i>=r || j<0 || j>=c || grid[i][j] != 'O') return;
    grid[i][j] = '#';
    dfs(i+1, j); dfs(i-1, j); dfs(i, j+1); dfs(i, j-1);
}
int main() {
    scanf("%d%d", &r, &c);
    for(int i=0; i<r; i++) scanf("%s", grid[i]);
    for(int i=0; i<r; i++) { dfs(i, 0); dfs(i, c-1); }
    for(int j=0; j<c; j++) { dfs(0, j); dfs(r-1, j); }
    for(int i=0; i<r; i++) for(int j=0; j<c; j++) {
        if(grid[i][j] == 'O') grid[i][j] = 'X';
        else if(grid[i][j] == '#') grid[i][j] = 'O';
    }
    for(int i=0; i<r; i++) printf("%s\n", grid[i]);
    return 0;
}
