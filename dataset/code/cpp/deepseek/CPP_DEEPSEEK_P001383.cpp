#include <iostream>
#include <unordered_map>
#include <vector>
using namespace std;

int main() {
    int N, M;
    cin >> N >> M;
    vector<int> A(N);
    unordered_map<int, int> mapA;
    for (int i = 0; i < N; i++) {
        cin >> A[i];
        mapA[A[i]]++;
    }
    vector<int> B(M);
    for (int i = 0; i < M; i++) {
        cin >> B[i];
    }
    for (int i = 0; i < M; i++) {
        if (mapA.find(B[i]) != mapA.end()) {
            cout << B[i] << " ";
            if (mapA[B[i]] > 1) {
                cout << mapA[B[i]] << "\n";
            } else {
                mapA.erase(B[i]);
            }
        } else {
            cout << "0\n";
        }
    }
    return 0;
}