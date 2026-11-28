#include <iostream>
#include <vector>
#include <string>
#include <set>
using namespace std;

int R, C;
vector<vector<char>> grid;
vector<string> dict;
set<string> foundWords;

struct TrieNode {
    TrieNode* children[26];
    bool isEnd;
    TrieNode() {
        for (int i = 0; i < 26; ++i) children[i] = nullptr;
        isEnd = false;
    }
};

void insert(TrieNode* root, string word) {
    TrieNode* node = root;
    for (char c : word) {
        if (!node->children[c-'a']) node->children[c-'a'] = new TrieNode();
        node = node->children[c-'a'];
    }
    node->isEnd = true;
}

void dfs(int r, int c, TrieNode* node, string current, vector<vector<bool>>& visited) {
    if (node->isEnd) {
        foundWords.insert(current);
    }
    
    int dr[] = {-1, 1, 0, 0};
    int dc[] = {0, 0, -1, 1};
    
    for (int k = 0; k < 4; ++k) {
        int nr = r + dr[k];
        int nc = c + dc[k];
        if (nr >= 0 && nr < R && nc >= 0 && nc < C && !visited[nr][nc]) {
            char ch = grid[nr][nc];
            if (node->children[ch-'a']) {
                visited[nr][nc] = true;
                dfs(nr, nc, node->children[ch-'a'], current + ch, visited);
                visited[nr][nc] = false;
            }
        }
    }
}

int main() {
    cin >> R >> C;
    grid.assign(R, vector<char>(C));
    for (int i = 0; i < R; ++i) {
        for (int j = 0; j < C; ++j) {
            cin >> grid[i][j];
        }
    }
    
    int n;
    cin >> n;
    dict.resize(n);
    TrieNode* root = new TrieNode();
    for (int i = 0; i < n; ++i) {
        cin >> dict[i];
        insert(root, dict[i]);
    }
    
    vector<vector<bool>> visited(R, vector<bool>(C, false));
    for (int i = 0; i < R; ++i) {
        for (int j = 0; j < C; ++j) {
            char ch = grid[i][j];
            if (root->children[ch-'a']) {
                visited[i][j] = true;
                dfs(i, j, root->children[ch-'a'], string(1, ch), visited);
                visited[i][j] = false;
            }
        }
    }
    
    for (const string& w : foundWords) {
        cout << w << endl;
    }
    
    return 0;
}
