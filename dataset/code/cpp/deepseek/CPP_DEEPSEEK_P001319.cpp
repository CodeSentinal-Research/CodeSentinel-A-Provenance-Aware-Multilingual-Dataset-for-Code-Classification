#include <iostream>
#include <vector>
#include <set>
#include <string>
using namespace std;

const int dx[4] = {-1, 0, 1, 0};
const int dy[4] = {0, 1, 0, -1};

bool isValid(int x, int y, int row, int col) {
    return x >= 0 && x < row && y >= 0 && y < col;
}

struct TrieNode {
    TrieNode *child[26];
    bool isEndOfWord;
    vector<string> words;
    TrieNode() {
        for(int i = 0; i < 26; i++)
            child[i] = NULL;
        isEndOfWord = false;
    }
};

void insert(TrieNode *root, string word, int index) {
    TrieNode *node = root;
    for(int i = index; i < word.size(); i++) {
        if(node->child[word[i] - 'a'] == NULL)
            node->child[word[i] - 'a'] = new TrieNode();
        node = node->child[word[i] - 'a'];
    }
    node->isEndOfWord = true;
    node->words.push_back(word);
}

void dfs(char grid[101][101], int row, int col, int x, int y, TrieNode *root, set<string> &result) {
    if(root == NULL) return;
    char aux = grid[x][y];
    grid[x][y] = '*';
    string word = string(1, aux);
    if(root->isEndOfWord) {
        for(int i = 0; i < root->words.size(); i++)
            result.insert(root->words[i]);
    }
    for(int i = 0; i < 4; i++) {
        int newx = x + dx[i];
        int newy = y + dy[i];
        if(isValid(newx, newy, row, col))
            dfs(grid, row, col, newx, newy, root, result);
    }
    grid[x][y] = aux;
}

int main() {
    int R, C;
    cin >> R >> C;
    char grid[101][101];
    for(int i = 0; i < R; i++)
        for(int j = 0; j < C; j++)
            cin >> grid[i][j];
    int N;
    cin >> N;
    set<string> result;
    TrieNode *root = new TrieNode();
    for(int i = 0; i < N; i++) {
        string word;
        cin >> word;
        insert(root, word, 0);
    }
    for(int i = 0; i < R; i++) {
        for(int j = 0; j < C; j++) {
            dfs(grid, R, C, i, j, root, result);
        }
    }
    for(auto &word : result)
        cout << word << endl;
    return 0;
}