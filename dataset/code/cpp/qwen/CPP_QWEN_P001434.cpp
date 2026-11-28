#include <iostream>
#include <vector>
#include <string>
using namespace std;

int main() {
    int n;
    cin >> n;
    vector<pair<int, int>> moves(n);
    for (int i = 0; i < n; ++i) {
        cin >> moves[i].first >> moves[i].second;
    }
    
    vector<vector<char>> board(3, vector<char>(3, '.'));
    string winner = "Pending";
    
    for (int i = 0; i < n; ++i) {
        int r = moves[i].first, c = moves[i].second;
        char player = (i % 2 == 0) ? 'X' : 'O';
        board[r][c] = player;
        
        // Check win
        bool win = true;
        for (int k = 0; k < 3; ++k) if (board[r][k] != player) win = false;
        if (win) winner = (player == 'X') ? "A" : "B";
        
        win = true;
        for (int k = 0; k < 3; ++k) if (board[k][c] != player) win = false;
        if (win) winner = (player == 'X') ? "A" : "B";
        
        if (r == c) {
            win = true;
            for (int k = 0; k < 3; ++k) if (board[k][k] != player) win = false;
            if (win) winner = (player == 'X') ? "A" : "B";
        }
        
        if (r + c == 2) {
            win = true;
            for (int k = 0; k < 3; ++k) if (board[k][2-k] != player) win = false;
            if (win) winner = (player == 'X') ? "A" : "B";
        }
    }
    
    if (winner == "Pending" && n == 9) winner = "Draw";
    
    cout << winner << endl;
    return 0;
}
