#include <iostream>
#include <vector>
using namespace std;

bool isSafe(int x, int y, vector<vector<int>>& sol, int N) {
    return (x >= 0 && x < N && y >= 0 && y < N && sol[x][y] == -1);
}

bool solveKTUtil(int x, int y, int movei, vector<vector<int>>& sol, int xMove[], int yMove[], int N) {
    if (movei == N * N) return true;
    
    for (int k = 0; k < 8; k++) {
        int next_x = x + xMove[k];
        int next_y = y + yMove[k];
        if (isSafe(next_x, next_y, sol, N)) {
            sol[next_x][next_y] = movei;
            if (solveKTUtil(next_x, next_y, movei + 1, sol, xMove, yMove, N)) return true;
            sol[next_x][next_y] = -1;
        }
    }
    return false;
}

int main() {
    int N, startX, startY;
    cin >> N >> startX >> startY;
    
    vector<vector<int>> sol(N, vector<int>(N, -1));
    int xMove[8] = { 2, 1, -1, -2, -2, -1, 1, 2 };
    int yMove[8] = { 1, 2, 2, 1, -1, -2, -2, -1 };
    
    sol[startX][startY] = 0;
    
    if (solveKTUtil(startX, startY, 1, sol, xMove, yMove, N)) {
        for (int i = 0; i < N; ++i) {
            for (int j = 0; j < N; ++j) {
                if (j > 0) cout << " ";
                cout << sol[i][j];
            }
            cout << endl;
        }
    } else {
        cout << -1 << endl;
    }
    return 0;
}
