#include <iostream>
#include <vector>
using namespace std;

int main() {
    int N;
    cin >> N;
    vector<vector<int>> A(N, vector<int>(N));
    for (int i = 0; i < N; ++i)
        for (int j = 0; j < N; ++j)
            cin >> A[i][j];
            
    bool symmetric = true;
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < N; ++j) {
            if (A[i][j] != A[j][i]) {
                symmetric = false;
                break;
            }
        }
        if (!symmetric) break;
    }
    cout << (symmetric ? "true" : "false") << endl;
    return 0;
}
