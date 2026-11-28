#include <iostream>
using namespace std;

int main() {
    long long N;
    cin >> N;
    long long sq = N * N;
    long long sum = 0;
    while (sq > 0) {
        sum += sq % 10;
        sq /= 10;
    }
    cout << (sum == N ? "true" : "false") << endl;
    return 0;
}
