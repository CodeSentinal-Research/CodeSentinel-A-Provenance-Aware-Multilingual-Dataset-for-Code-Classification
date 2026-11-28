#include <iostream>
using namespace std;

int main() {
    long long N;
    cin >> N;
    long long prod = 1;
    if (N == 0) prod = 0;
    while (N > 0) {
        prod *= N % 10;
        N /= 10;
    }
    cout << prod << endl;
    return 0;
}
