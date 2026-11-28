#include <vector>
#include <string>

class Solution {
    struct TrieNode {
        TrieNode* children[26] = {nullptr};
        std::string word = "";
    };

    void dfs(std::vector<std::vector<char>>& board, int r, int c, TrieNode* node, std::vector<std::string>& res) {
        char ch = board[r][c];
        if (ch == '#' || !node->children[ch - 'a']) return;

        TrieNode* next = node->children[ch - 'a'];
        if (!next->word.empty()) {
            res.push_back(next->word);
            next->word = "";
        }

        board[r][c] = '#';
        int dr[] = {1, -1, 0, 0};
        int dc[] = {0, 0, 1, -1};

        for (int i = 0; i < 4; i++) {
            int nr = r + dr[i], nc = c + dc[i];
            if (nr >= 0 && nr < (int)board.size() && nc >= 0 && nc < (int)board[0].size() && board[nr][nc] != '#') {
                dfs(board, nr, nc, next, res);
            }
        }
        board[r][c] = ch;
    }
public:
    std::vector<std::string> findWords(std::vector<std::vector<char>>& board, std::vector<std::string>& words) {
        TrieNode* root = new TrieNode();
        for (const auto& w : words) {
            TrieNode* node = root;
            for (char c : w) {
                if (!node->children[c - 'a']) node->children[c - 'a'] = new TrieNode();
                node = node->children[c - 'a'];
            }
            node->word = w;
        }

        std::vector<std::string> res;
        int m = board.size(), n = board[0].size();
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                dfs(board, i, j, root, res);
            }
        }
        return res;
    }
};