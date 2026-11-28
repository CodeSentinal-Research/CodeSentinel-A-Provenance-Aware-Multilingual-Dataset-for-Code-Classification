#include <iostream>
using namespace std;

int countPaths(int N, int M, int grid[N][M]) {
    int count[N][M];
    for(int i = 0; i < N; i++) {
        for(int j = 0; j < M; j++) {
            count[i][j] = 0;
        }
    }

    for(int i = 0; i < N; i++) {
        count[i][0] = 1;
    }
    for(int j = 0; j < M; j++) {
        count[0][j] = 1;
    }

    for(int i = 1; i < N; i++) {
        for(int j = 1; j < M; j++) {
            if(grid[i][j] == 1) {
                count[i][j] = count[i-1][j] + count[i][j-1];
            }
        }
    }

    return count[N-1][M-1];
}

int main() {
    int N, M;
    cin >> N >> M;

    int grid[N][M];
    for(int i = 0; i < N; i++) {
        for(int j = 0; j < M; j++) {
            cin >> grid[i][j];
        }
    }

    cout << countPaths(N, M, grid);

    return 0;
}