#include <iostream>
#include <vector>
#include <string>
using namespace std;

bool exist(vector<vector<char>>& board, string word, int i, int j, int index) {
    if (index == word.length()) return true;
    if (i < 0 || i >= board.size() || j < 0 || j >= board[0].size() || board[i][j] != word[index]) return false;
    
    char temp = board[i][j];
    board[i][j] = '#';
    
    bool found = exist(board, word, i+1, j, index+1) ||
                 exist(board, word, i-1, j, index+1) ||
                 exist(board, word, i, j+1, index+1) ||
                 exist(board, word, i, j-1, index+1);
                 
    board[i][j] = temp;
    return found;
}

int main() {
    int N, M;
    cin >> N >> M;
    vector<vector<char>> board(N, vector<char>(M));
    for (int i = 0; i < N; ++i)
        for (int j = 0; j < M; ++j)
            cin >> board[i][j];
            
    string word;
    cin >> word;
    
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < M; ++j) {
            if (exist(board, word, i, j, 0)) {
                cout << "true" << endl;
                return 0;
            }
        }
    }
    cout << "false" << endl;
    return 0;
}
