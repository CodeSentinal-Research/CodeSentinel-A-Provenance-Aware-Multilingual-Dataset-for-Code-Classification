#include <iostream>
#include <vector>
using namespace std;

int main() {
    int N;
    cin >> N;
    vector<vector<int>> A(N, vector<int>(N));
    long long sum = 0;
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < N; ++j) {
            cin >> A[i][j];
            if (i == j) sum += A[i][j];
            if (i + j == N - 1 && i != j) sum += A[i][j];
        }
    }
    // If N is odd, center was added once in main diag, skipped in anti-diag check (i!=j). Correct.
    cout << sum << endl;
    return 0;
}
