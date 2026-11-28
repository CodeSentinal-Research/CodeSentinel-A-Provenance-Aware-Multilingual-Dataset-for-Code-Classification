#include <iostream>
using namespace std;

int main() {
    long long M, N;
    cin >> M >> N;

    long long sum = 0;
    for (long long i = 0; i < M; i++) {
        long long a;
        cin >> a;
        sum += a;
    }

    long long minInsertions = 0;
    while (sum <= N) {
        sum += N;
        minInsertions++;
    }

    cout << minInsertions << endl;

    return 0;
}