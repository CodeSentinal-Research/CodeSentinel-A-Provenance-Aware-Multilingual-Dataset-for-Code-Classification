#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

int main() {
    int N, M, P;
    cin >> N >> M >> P;
    
    unordered_map<int, long long> mapA, mapB;
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < M; ++j) {
            long long val;
            cin >> val;
            if (val != 0) mapA[i * M + j] = val;
        }
    }
    
    for (int i = 0; i < M; ++i) {
        for (int j = 0; j < P; ++j) {
            long long val;
            cin >> val;
            if (val != 0) mapB[i * P + j] = val;
        }
    }
    
    vector<vector<long long>> C(N, vector<long long>(P, 0));
    for (auto& [keyA, valA] : mapA) {
        int rA = keyA / M;
        int cA = keyA % M;
        for (auto& [keyB, valB] : mapB) {
            int rB = keyB / P;
            int cB = keyB % P;
            if (cA == rB) {
                C[rA][cB] += valA * valB;
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
