#include <iostream>
using namespace std;

int main() {
    int n;
    cin >> n;
    int sq = n * n, sum = 0;
    while (sq > 0) { sum += sq % 10; sq /= 10; }
    cout << (sum == n ? "Neon" : "Not Neon") << endl;
    return 0;
}
