#include <iostream>
#include <vector>

using namespace std;

int R, C;
int sr, sc, er, ec;
int ans = 0;
int vis[20][20];
char grid[20][20];
int dx[4] = {-1, 0, 1, 0};
int dy[4] = {0, 1, 0, -1};

bool isvalid(int x, int y) {
    if (x < 0 || y < 0 || x >= R || y >= C || vis[x][y] == 1 || grid[x][y] == '#')
        return false;
    return true;
}

void dfs(int x, int y, int cnt) {
    if (x == er && y == ec && cnt == 0) {
        ans++;
        return;
    }
    for (int i = 0; i < 4; i++) {
        int nx = x + dx[i], ny = y + dy[i];
        if (isvalid(nx, ny)) {
            vis[nx][ny] = 1;
            dfs(nx, ny, cnt-1);
            vis[nx][ny] = 0;
        }
    }
}

int main() {
    cin >> R >> C;
    for (int i = 0; i < R; i++) {
        for (int j = 0; j < C; j++) {
            cin >> grid[i][j];
            if (grid[i][j] == 'S') {
                sr = i;
                sc = j;
            }
            if (grid[i][j] == 'E') {
                er = i;
                ec = j;
            }
        }
    }
    vis[sr][sc] = 1;
    dfs(sr, sc, R*C);
    cout << ans << "\n";
    return 0;
}