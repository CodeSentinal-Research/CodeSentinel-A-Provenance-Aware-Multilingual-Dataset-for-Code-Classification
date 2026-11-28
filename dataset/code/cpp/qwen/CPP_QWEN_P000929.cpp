#include <iostream>
#include <vector>
using namespace std;

int main() {
    int N, M;
    cin >> N >> M;
    vector<vector<long long>> A(N, vector<long long>(M));
    vector<vector<long long>> B(N, vector<long long>(M));
    
    for (int i = 0; i < N; ++i)
        for (int j = 0; j < M; ++j)
            cin >> A[i][j];
            
    for (int i = 0; i < N; ++i)
        for (int j = 0; j < M; ++j)
            cin >> B[i][j];
            
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < M; ++j) {
            if (j > 0) cout << " ";
            cout << A[i][j] + B[i][j];
        }
        cout << endl;
    }
    return 0;
}
