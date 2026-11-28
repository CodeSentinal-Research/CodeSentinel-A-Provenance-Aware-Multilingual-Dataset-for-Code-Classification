#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#define MAX_N 55
int forest[MAX_N][MAX_N];
bool vis[MAX_N][MAX_N];
int qr[MAX_N * MAX_N], qc[MAX_N * MAX_N], qd[MAX_N * MAX_N];
typedef struct { int val, r, c; } Tree;
Tree trees[MAX_N * MAX_N];
int cmp(const void* a, const void* b) { return ((Tree*)a)->val - ((Tree*)b)->val; }
int dr[4] = {-1, 1, 0, 0}, dc[4] = {0, 0, -1, 1};
int bfs(int m, int n, int sr, int sc, int tr, int tc) {
    if (sr == tr && sc == tc) return 0;
    memset(vis, 0, sizeof(vis));
    int head = 0, tail = 0;
    qr[tail] = sr; qc[tail] = sc; qd[tail++] = 0;
    vis[sr][sc] = true;
    while (head < tail) {
        int r = qr[head], c = qc[head], d = qd[head++];
        for (int i = 0; i < 4; i++) {
            int nr = r + dr[i], nc = c + dc[i];
            if (nr >= 0 && nr < m && nc >= 0 && nc < n && forest[nr][nc] != 0 && !vis[nr][nc]) {
                if (nr == tr && nc == tc) return d + 1;
                vis[nr][nc] = true;
                qr[tail] = nr; qc[tail] = nc; qd[tail++] = d + 1;
            }
        }
    }
    return -1;
}
int main() {
    int m, n;
    if (scanf("%d %d", &m, &n) == 2) {
        int t_cnt = 0;
        for (int r = 0; r < m; r++) {
            for (int c = 0; c < n; c++) {
                scanf("%d", &forest[r][c]);
                if (forest[r][c] > 1) {
                    trees[t_cnt].val = forest[r][c];
                    trees[t_cnt].r = r;
                    trees[t_cnt].c = c;
                    t_cnt++;
                }
            }
        }
        qsort(trees, t_cnt, sizeof(Tree), cmp);
        int total = 0, cur_r = 0, cur_c = 0;
        for (int i = 0; i < t_cnt; i++) {
            int steps = bfs(m, n, cur_r, cur_c, trees[i].r, trees[i].c);
            if (steps == -1) { printf("-1\n"); return 0; }
            total += steps;
            cur_r = trees[i].r; cur_c = trees[i].c;
        }
        printf("%d\n", total);
    }
    return 0;
}