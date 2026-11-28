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
            
    bool identity = true;
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < N; ++j) {
            if (i == j && A[i][j] != 1) identity = false;
            if (i != j && A[i][j] != 0) identity = false;
        }
    }
    cout << (identity ? "true" : "false") << endl;
    return 0;
}
