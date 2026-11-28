#include <iostream>
using namespace std;

int main() {
    long long N;
    cin >> N;
    int maxD = 0, minD = 9;
    if (N == 0) { maxD = 0; minD = 0; }
    while (N > 0) {
        int d = N % 10;
        maxD = max(maxD, d);
        minD = min(minD, d);
        N /= 10;
    }
    cout << maxD << " " << minD << endl;
    return 0;
}
