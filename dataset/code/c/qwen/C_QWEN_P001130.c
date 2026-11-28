#include <stdio.h>
int parent[4000001];
int find(int i) { while(parent[i] != i) i = parent[i]; return i; }
void unite(int i, int j) { parent[find(i)] = find(j); }
int main() {
    int n; scanf("%d", &n);
    char grid[n][n+1];
    for(int i=0; i<n; i++) scanf("%s", grid[i]);
    int cells = (n+1)*(n+1);
    for(int i=0; i<cells; i++) parent[i] = i;
    int regions = cells;
    for(int i=0; i<n; i++) for(int j=0; j<n; j++) {
        int top = i*(n+1)+j, bot = (i+1)*(n+1)+j, left = i*(n+1)+j, right = i*(n+1)+j+1;
        if(grid[i][j] == '/') { unite(top, right); unite(bot, left); }
        else if(grid[i][j] == '\\') { unite(top, left); unite(bot, right); }
        else { unite(top, bot); unite(top, right); unite(top, left); }
    }
    int count = 0;
    for(int i=0; i<cells; i++) if(find(i) == i) count++;
    printf("%d\n", count);
    return 0;
}
