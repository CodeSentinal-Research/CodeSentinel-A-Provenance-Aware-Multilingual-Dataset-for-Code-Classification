#include <iostream>
#include <vector>
#include <climits>
using namespace std;

int N;
vector<vector<int>> board;
vector<bool> visited;
bool found = false;

int dx[] = {2, 1, -1, -2, -2, -1, 1, 2};
int dy[] = {1, 2, 2, 1, -1, -2, -2, -1};

void solveKT(int x, int y, int movei, vector<vector<int>>& sol) {
    if (movei == N * N) {
        found = true;
        return;
    }
    
    for (int k = 0; k < 8; ++k) {
        int next_x = x + dx[k];
        int next_y = y + dy[k];
        if (next_x >= 0 && next_x < N && next_y >= 0 && next_y < N && sol[next_x][next_y] == -1) {
            sol[next_x][next_y] = movei;
            solveKT(next_x, next_y, movei + 1, sol);
            if (found) return;
            sol[next_x][next_y] = -1;
        }
    }
}

int main() {
    int startX, startY;
    cin >> N >> startX >> startY;
    
    board.assign(N, vector<int>(N, -1));
    vector<vector<int>> sol(N, vector<int>(N, -1));
    sol[startX][startY] = 0;
    
    solveKT(startX, startY, 1, sol);
    
    if (found) {
        for (int i = 0; i < N; ++i) {
            for (int j = 0; j < N; ++j) {
                if (j > 0) cout << " ";
                cout << sol[i][j];
            }
            cout << endl;
        }
    } else {
        cout << "IMPOSSIBLE" << endl;
    }
    return 0;
}
