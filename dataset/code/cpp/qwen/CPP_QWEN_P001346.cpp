#include <iostream>
#include <vector>
#include <string>
using namespace std;

int N;
vector<string> grid;
vector<string> words;
vector<bool> used;

bool canPlaceHorizontally(int r, int c, const string& word) {
    if (c + word.length() > N) return false;
    if (c > 0 && grid[r][c-1] != '+') return false;
    if (c + word.length() < N && grid[r][c+word.length()] != '+') return false;
    
    for (int i = 0; i < word.length(); ++i) {
        if (grid[r][c+i] != '-' && grid[r][c+i] != word[i]) return false;
    }
    return true;
}

bool canPlaceVertically(int r, int c, const string& word) {
    if (r + word.length() > N) return false;
    if (r > 0 && grid[r-1][c] != '+') return false;
    if (r + word.length() < N && grid[r+word.length()][c] != '+') return false;
    
    for (int i = 0; i < word.length(); ++i) {
        if (grid[r+i][c] != '-' && grid[r+i][c] != word[i]) return false;
    }
    return true;
}

void placeHorizontally(int r, int c, const string& word, vector<char>& backup) {
    for (int i = 0; i < word.length(); ++i) {
        backup.push_back(grid[r][c+i]);
        grid[r][c+i] = word[i];
    }
}

void removeHorizontally(int r, int c, const string& word, const vector<char>& backup) {
    for (int i = 0; i < word.length(); ++i) {
        grid[r][c+i] = backup[i];
    }
}

void placeVertically(int r, int c, const string& word, vector<char>& backup) {
    for (int i = 0; i < word.length(); ++i) {
        backup.push_back(grid[r+i][c]);
        grid[r+i][c] = word[i];
    }
}

void removeVertically(int r, int c, const string& word, const vector<char>& backup) {
    for (int i = 0; i < word.length(); ++i) {
        grid[r+i][c] = backup[i];
    }
}

bool solve(int wordIdx) {
    if (wordIdx == words.size()) {
        for (int i = 0; i < N; ++i)
            for (int j = 0; j < N; ++j)
                if (grid[i][j] == '-') return false;
        return true;
    }
    
    for (int i = 0; i < words.size(); ++i) {
        if (!used[i]) {
            used[i] = true;
            for (int r = 0; r < N; ++r) {
                for (int c = 0; c < N; ++c) {
                    if (canPlaceHorizontally(r, c, words[i])) {
                        vector<char> backup;
                        placeHorizontally(r, c, words[i], backup);
                        if (solve(wordIdx + 1)) return true;
                        removeHorizontally(r, c, words[i], backup);
                    }
                }
            }
            for (int r = 0; r < N; ++r) {
                for (int c = 0; c < N; ++c) {
                    if (canPlaceVertically(r, c, words[i])) {
                        vector<char> backup;
                        placeVertically(r, c, words[i], backup);
                        if (solve(wordIdx + 1)) return true;
                        removeVertically(r, c, words[i], backup);
                    }
                }
            }
            used[i] = false;
        }
    }
    return false;
}

int main() {
    int W;
    cin >> N >> W;
    grid.resize(N);
    for (int i = 0; i < N; ++i) cin >> grid[i];
    
    words.resize(W);
    for (int i = 0; i < W; ++i) cin >> words[i];
    used.assign(W, false);
    
    if (solve(0)) {
        for (int i = 0; i < N; ++i) cout << grid[i] << endl;
    }
    return 0;
}
