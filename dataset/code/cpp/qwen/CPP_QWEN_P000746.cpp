#include <iostream>
using namespace std;

int josephus(int n, int k) {
    if (n == 1) return 0;
    return (josephus(n - 1, k) + k) % n;
}

int main() {
    int N, K;
    cin >> N >> K;
    cout << josephus(N, K) + 1 << endl; // Convert 0-indexed to 1-indexed
    return 0;
}
