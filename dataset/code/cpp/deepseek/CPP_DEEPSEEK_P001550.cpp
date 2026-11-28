#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

int main() {
    int N, K;
    cin >> N >> K;

    vector<int> A(N);
    for (int i = 0; i < N; i++) {
        cin >> A[i];
    }

    for (int i = 0; i <= N - K; i++) {
        int sum = 0;
        for (int j = i; j < i + K; j++) {
            int diff = abs(A[j] - A[j - i % K]);
            sum += diff;
        }
        cout << sum << endl;
    }

    return 0;
}