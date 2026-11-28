#include <vector>
#include <string>

class Solution {
    bool dfs(std::vector<std::vector<char>>& board, const std::string& word, int r, int c, int k) {
        if (k == (int)word.length()) return true;
        if (r < 0 || r >= (int)board.size() || c < 0 || c >= (int)board[0].size() || board[r][c] != word[k]) {
            return false;
        }

        char tmp = board[r][c];
        board[r][c] = '#';

        bool found = dfs(board, word, r + 1, c, k + 1) ||
                     dfs(board, word, r - 1, c, k + 1) ||
                     dfs(board, word, r, c + 1, k + 1) ||
                     dfs(board, word, r, c - 1, k + 1);

        board[r][c] = tmp;
        return found;
    }
public:
    bool exist(std::vector<std::vector<char>>& board, std::string word) {
        int m = board.size(), n = board[0].size();
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (dfs(board, word, i, j, 0)) return true;
            }
        }
        return false;
    }
};