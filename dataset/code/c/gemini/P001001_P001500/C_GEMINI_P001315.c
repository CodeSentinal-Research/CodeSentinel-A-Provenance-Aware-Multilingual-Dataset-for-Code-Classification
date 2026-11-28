#include <stdio.h>
#include <stdbool.h>
#include <string.h>

int n;
int maze[50][50];
bool visited[50][50];
char path[2500];
int pathLen = 0;
bool foundAny = false;

int dr[] = {1, 0, 0, -1};
int dc[] = {0, -1, 1, 0};
char dChars[] = {'D', 'L', 'R', 'U'};

void backtrack(int r, int c) {
    if (r == n - 1 && c == n - 1) {
        path[pathLen] = '\0';
        if (foundAny) printf(" ");
        printf("%s", path);
        foundAny = true;
        return;
    }

    visited[r][c] = true;
    for (int i = 0; i < 4; i++) {
        int nr = r + dr[i], nc = c + dc[i];
        if (nr >= 0 && nr < n && nc >= 0 && nc < n && !visited[nr][nc] && maze[nr][nc] == 1) {
            path[pathLen++] = dChars[i];
            backtrack(nr, nc);
            pathLen--;
        }
    }
    visited[r][c] = false;
}

int main() {
    if (scanf("%d", &n) == 1) {
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) scanf("%d", &maze[i][j]);
        }

        if (maze[0][0] == 1 && maze[n - 1][n - 1] == 1) {
            memset(visited, 0, sizeof(visited));
            backtrack(0, 0);
        }

        if (!foundAny) printf("-1");
        printf("\n");
    }
    return 0;
}