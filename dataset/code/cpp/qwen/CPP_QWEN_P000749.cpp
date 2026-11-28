#include <iostream>
#include <string>
#include <vector>
using namespace std;

void generatePaths(int N, int M, int i, int j, string path, vector<string>& result) {
    if (i == N - 1 && j == M - 1) {
        result.push_back(path);
        return;
    }
    
    // Horizontal jumps H1, H2...
    for (int k = 1; k < M; ++k) {
        if (j + k < M) generatePaths(N, M, i, j + k, path + "H" + to_string(k), result);
        else break;
    }
    // Vertical jumps V1, V2...
    for (int k = 1; k < N; ++k) {
        if (i + k < N) generatePaths(N, M, i + k, j, path + "V" + to_string(k), result);
        else break;
    }
    // Diagonal jumps D1, D2...
    for (int k = 1; k < min(N, M); ++k) {
        if (i + k < N && j + k < M) generatePaths(N, M, i + k, j + k, path + "D" + to_string(k), result);
        else break;
    }
}

int main() {
    int N, M;
    cin >> N >> M;
    vector<string> result;
    generatePaths(N, M, 0, 0, "", result);
    
    for (const string& p : result) {
        cout << p << endl;
    }
    return 0;
}
