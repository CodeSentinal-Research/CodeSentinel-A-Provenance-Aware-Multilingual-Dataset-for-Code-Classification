#include <iostream>
#include <vector>
using namespace std;

int main() {
    int N, M, P;
    cin >> N >> M >> P;
    vector<vector<long long>> A(N, vector<long long>(M));
    vector<vector<long long>> B(M, vector<long long>(P));
    
    for (int i = 0; i < N; ++i)
        for (int j = 0; j < M; ++j)
            cin >> A[i][j];
            
    for (int i = 0; i < M; ++i)
        for (int j = 0; j < P; ++j)
            cin >> B[i][j];
            
    vector<vector<long long>> C(N, vector<long long>(P, 0));
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < P; ++j) {
            for (int k = 0; k < M; ++k) {
                C[i][j] += A[i][k] * B[k][j];
            }
        }
    }
    
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < P; ++j) {
            if (j > 0) cout << " ";
            cout << C[i][j];
        }
        cout << endl;
    }
    return 0;
}
