#include <iostream>
using namespace std;

int main() {
    long long N;
    int K;
    cin >> N >> K;
    cout << (N & ~(1LL << K)) << endl;
    return 0;
}
