#include <iostream>
#include <vector>
using namespace std;

int main() {
    int N;
    cin >> N;

    vector<vector<int>> mat(N, vector<int>(N));
    for(int i = 0; i < N; i++) {
        for(int j = 0; j < N; j++) {
            cin >> mat[i][j];
        }
    }

    int maxDiff = -1;
    for(int c = 0; c < N; c++) {
        for(int d = 0; d < N; d++) {
            if(c > d && mat[c][d] > maxDiff) {
                maxDiff = mat[c][d];
            }
        }
    }

    cout << maxDiff << endl;
    return 0;
}