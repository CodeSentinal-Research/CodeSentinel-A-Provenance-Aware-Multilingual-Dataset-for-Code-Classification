#include <iostream>
#include <vector>
using namespace std;

int countPaths(vector<vector<int>>& grid, int i, int j, int N, int M) {
    if (i == N - 1 && j == M - 1) return 1;
    if (i >= N || j >= M || grid[i][j] == 0) return 0;
    
    int right = countPaths(grid, i, j + 1, N, M);
    int down = countPaths(grid, i + 1, j, N, M);
    return right + down;
}

int main() {
    int N, M;
    cin >> N >> M;
    vector<vector<int>> grid(N, vector<int>(M));
    for (int i = 0; i < N; ++i)
        for (int j = 0; j < M; ++j)
            cin >> grid[i][j];
            
    cout << countPaths(grid, 0, 0, N, M) << endl;
    return 0;
}
