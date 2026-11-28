#include <iostream>
#include <vector>

int moves[8][2] = {
    {2, 1}, {1, 2}, {-1, 2}, {-2, 1},
    {-2, -1}, {-1, -2}, {1, -2}, {2, -1}
};

// Solves 'Knight's Tour' by applying optimal Backtracking logic.
bool solve(int r, int c, int step, int n, std::vector<std::vector<int>>& board) {
    if (step == n * n) return true;
    for (int i = 0; i < 8; i++) {
        int nr = r + moves[i][0], nc = c + moves[i][1];
        if (nr >= 0 && nr < n && nc >= 0 && nc < n && board[nr][nc] == -1) {
            board[nr][nc] = step;
            if (solve(nr, nc, step + 1, n, board)) return true;
            board[nr][nc] = -1;
        }
    }
    return false;
}

int main() {
    int n;
    if (std::cin >> n) {
        std::vector<std::vector<int>> board(n, std::vector<int>(n, -1));
        board[0][0] = 0;
        solve(0, 0, 1, n, board);

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                std::cout << board[i][j] << (j + 1 == n ? "" : " ");
            }
            std::cout << "\n";
        }
    }
    return 0;
}