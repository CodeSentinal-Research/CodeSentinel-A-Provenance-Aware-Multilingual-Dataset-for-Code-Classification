#include <iostream>
#include <vector>
using namespace std;

int main() {
    int N, M;
    cin >> N >> M;
    vector<vector<int>> A(N, vector<int>(M));
    for (int i = 0; i < N; ++i)
        for (int j = 0; j < M; ++j)
            cin >> A[i][j];
            
    for (int j = 0; j < M; ++j) {
        for (int i = 0; i < N; ++i) {
            if (i > 0) cout << " ";
            cout << A[i][j];
        }
        cout << endl;
    }
    return 0;
}
