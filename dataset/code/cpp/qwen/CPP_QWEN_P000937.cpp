#include <iostream>
#include <vector>
using namespace std;

void multiply(vector<vector<long long>>& A, vector<vector<long long>>& B, vector<vector<long long>>& Res, int N) {
    vector<vector<long long>> Temp(N, vector<long long>(N, 0));
    for (int i = 0; i < N; ++i) {
        for (int k = 0; k < N; ++k) {
            if (A[i][k] == 0) continue;
            for (int j = 0; j < N; ++j) {
                Temp[i][j] += A[i][k] * B[k][j];
            }
        }
    }
    Res = Temp;
}

void powerMatrix(vector<vector<long long>>& A, long long K, int N) {
    vector<vector<long long>> Res(N, vector<long long>(N, 0));
    for (int i = 0; i < N; ++i) Res[i][i] = 1;
    
    vector<vector<long long>> Base = A;
    
    while (K > 0) {
        if (K & 1) {
            vector<vector<long long>> Temp;
            multiply(Res, Base, Temp, N);
            Res = Temp;
        }
        vector<vector<long long>> Temp;
        multiply(Base, Base, Temp, N);
        Base = Temp;
        K >>= 1;
    }
    
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < N; ++j) {
            if (j > 0) cout << " ";
            cout << Res[i][j];
        }
        cout << endl;
    }
}

int main() {
    int N;
    long long K;
    cin >> N >> K;
    vector<vector<long long>> A(N, vector<long long>(N));
    for (int i = 0; i < N; ++i)
        for (int j = 0; j < N; ++j)
            cin >> A[i][j];
            
    powerMatrix(A, K, N);
    return 0;
}
