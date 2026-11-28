#include <string>
#include <vector>
#include <unordered_set>

class Solution {
    std::vector<std::vector<std::string>> res;
    std::unordered_set<int> cols, posDiag, negDiag;

    void backtrack(int r, int n, std::vector<std::string>& board) {
        if (r == n) {
            res.push_back(board);
            return;
        }

        for (int c = 0; c < n; c++) {
            if (cols.count(c) || posDiag.count(r + c) || negDiag.count(r - c)) continue;
            cols.insert(c); posDiag.insert(r + c); negDiag.insert(r - c);
            board[r][c] = 'Q';

            backtrack(r + 1, n, board);

            cols.erase(c); posDiag.erase(r + c); negDiag.erase(r - c);
            board[r][c] = '.';
        }
    }
public:
    std::vector<std::vector<std::string>> solveNQueens(int n) {
        std::vector<std::string> board(n, std::string(n, '.'));
        backtrack(0, n, board);
        return res;
    }
};