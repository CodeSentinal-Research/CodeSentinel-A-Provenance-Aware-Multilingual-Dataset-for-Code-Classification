#include <iostream>
#include <string>
#include <vector>
using namespace std;

void findPaths(int N, int M, int i, int j, string path, vector<string>& result) {
    if (i == N - 1 && j == M - 1) {
        result.push_back(path);
        return;
    }
    if (i >= N || j >= M) return;
    
    // Horizontal
    findPaths(N, M, i, j + 1, path + "H", result);
    // Vertical
    findPaths(N, M, i + 1, j, path + "V", result);
    // Diagonal
    findPaths(N, M, i + 1, j + 1, path + "D", result);
}

int main() {
    int N, M;
    cin >> N >> M;
    vector<string> result;
    findPaths(N, M, 0, 0, "", result);
    
    for (const string& p : result) {
        cout << p << endl;
    }
    return 0;
}
