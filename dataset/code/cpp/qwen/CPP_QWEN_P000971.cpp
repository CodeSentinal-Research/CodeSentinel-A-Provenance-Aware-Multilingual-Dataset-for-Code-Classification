#include <iostream>
#include <vector>
using namespace std;

int main() {
    long long A, B, F0, F1;
    int N;
    cin >> A >> B >> F0 >> F1 >> N;
    
    if (N == 0) { cout << F0 << endl; return 0; }
    if (N == 1) { cout << F1 << endl; return 0; }
    
    vector<long long> F(N + 1);
    F[0] = F0;
    F[1] = F1;
    for (int i = 2; i <= N; ++i) {
        F[i] = A * F[i-1] + B * F[i-2];
    }
    cout << F[N] << endl;
    return 0;
}
