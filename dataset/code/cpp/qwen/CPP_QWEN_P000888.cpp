#include <iostream>
using namespace std;

int main() {
    long long N;
    cin >> N;
    long long sq = N * N;
    long long temp = N;
    int digits = 0;
    while (temp > 0) {
        digits++;
        temp /= 10;
    }
    
    long long mod = 1;
    for (int i = 0; i < digits; ++i) mod *= 10;
    
    cout << (sq % mod == N ? "true" : "false") << endl;
    return 0;
}
