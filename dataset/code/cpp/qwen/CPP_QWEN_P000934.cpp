#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    int N;
    cin >> N;
    vector<vector<int>> A(N, vector<int>(N));
    for (int i = 0; i < N; ++i)
        for (int j = 0; j < N; ++j)
            cin >> A[i][j];
            
    // Transpose
    for (int i = 0; i < N; ++i)
        for (int j = i + 1; j < N; ++j)
            swap(A[i][j], A[j][i]);
            
    // Reverse each row
    for (int i = 0; i < N; ++i)
        reverse(A[i].begin(), A[i].end());
        
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < N; ++j) {
            if (j > 0) cout << " ";
            cout << A[i][j];
        }
        cout << endl;
    }
    return 0;
}
