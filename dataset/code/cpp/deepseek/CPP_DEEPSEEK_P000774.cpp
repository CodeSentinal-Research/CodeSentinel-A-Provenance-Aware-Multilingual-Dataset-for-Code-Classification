Here is the C++ code for the problem:

#include <iostream>
#include <vector>

using namespace std;

bool solve(int x, int y, int idx, vector<vector<char>>& board, string word) {
    if (idx == word.size()) {
        return true;
    }

    if (x < 0 || y < 0 || x >= board.size() || y >= board[0].size()) {
        return false;
    }

    if (board[x][y] != word[idx]) {
        return false;
    }

    board[x][y] = '0';

    bool found = solve(x - 1, y, idx + 1, board, word) || 
                 solve(x + 1, y, idx + 1, board, word) || 
                 solve(x, y - 1, idx + 1, board, word) || 
                 solve(x, y + 1, idx + 1, board, word);

    board[x][y] = word[idx];

    return found;
}

bool wordExists(int N, int M, vector<vector<char>> board, string word) {
    int idx = 0;

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            if (board[i][j] == word[idx]) {
                if (solve(i, j, idx, board, word)) {
                    return true;
                }
            }
        }
    }

    return false;
}

int main() {
    vector<vector<char>> board = {{'a','b','c','d','e'},{'f','g','h','i','j'},{'k','l','m','n','o'},{'p','q','r','s','t'},{'u','v','w','x','y'}};
    string word = "abcsdt";
    int N = 5;
    int M = 5;

    cout << (wordExists(N, M, board, word) ? "Yes" : "No") << endl;

    return 0;
}

This code defines a recursive function `wordExists` which iterates over each cell in the grid. If a cell contains the first character of the word, it calls the `solve` function to check all adjacent cells. The `solve` function checks if the next character of the word can be found starting from the current cell, in all four directions (up, down, left, right). If a word can be found, it returns true. If no such word can be found, it returns false.