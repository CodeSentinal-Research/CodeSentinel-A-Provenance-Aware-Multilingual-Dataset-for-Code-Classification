#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include <stdlib.h>
int grid[32][32];
bool vis[32][32];
char results[1024][128];
int res_count = 0;
int dr[] = {1, 0, 0, -1};
int dc[] = {0, -1, 1, 0};
char dname[] = {'D', 'L', 'R', 'U'};
int cmp(const void* a, const void* b) { return strcmp((char*)a, (char*)b); }
void backtrack(int n, int r, int c, char* path, int path_len) {
    if (r == n - 1 && c == n - 1) {
        path[path_len] = '\0';
        strcpy(results[res_count++], path);
        return;
    }
    vis[r][c] = true;
    for (int i = 0; i < 4; i++) {
        int nr = r + dr[i], nc = c + dc[i];
        if (nr >= 0 && nr < n && nc >= 0 && nc < n && grid[nr][nc] == 1 && !vis[nr][nc]) {
            path[path_len] = dname[i];
            backtrack(n, nr, nc, path, path_len + 1);
        }
    }
    vis[r][c] = false;
}
int main() {
    int n;
    if (scanf("%d", &n) == 1) {
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) scanf("%d", &grid[i][j]);
        }
        if (grid[0][0] == 0 || grid[n - 1][n - 1] == 0) return 0;
        char path[128];
        backtrack(n, 0, 0, path, 0);
        qsort(results, res_count, sizeof(results[0]), cmp);
        for (int i = 0; i < res_count; i++) printf("%s\n", results[i]);
    }
    return 0;
}