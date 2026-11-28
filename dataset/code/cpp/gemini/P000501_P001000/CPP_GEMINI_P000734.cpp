#include <iostream>
#include <vector>
int dr[] = {-2, -1, 1, 2, 2, 1, -1, -2};
int dc[] = {1, 2, 2, 1, -1, -2, -2, -1};
bool backtrack(int n, int r, int c, int step, std::vector<std::vector<int>>& board) {
    if (step == n * n) return true;
    for (int i = 0; i < 8; i++) {
        int nr = r + dr[i], nc = c + dc[i];
        if (nr >= 0 && nr < n && nc >= 0 && nc < n && board[nr][nc] == -1) {
            board[nr][nc] = step;
            if (backtrack(n, nr, nc, step + 1, board)) return true;
            board[nr][nc] = -1;
        }
    }
    return false;
}
int main() {
    int n, sr, sc;
    if (std::cin >> n >> sr >> sc) {
        std::vector<std::vector<int>> board(n, std::vector<int>(n, -1));
        board[sr][sc] = 0;
        if (backtrack(n, sr, sc, 1, board)) {
            for (int i = 0; i < n; i++) {
                for (int j = 0; j < n; j++) std::cout << board[i][j] << (j == n - 1 ? "" : " ");
                std::cout << std::endl;
            }
        } else {
            std::cout << -1 << std::endl;
        }
    }
    return 0;
}