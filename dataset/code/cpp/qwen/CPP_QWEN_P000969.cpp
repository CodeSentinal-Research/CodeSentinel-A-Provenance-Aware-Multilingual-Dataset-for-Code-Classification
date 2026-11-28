#include <iostream>
#include <vector>
using namespace std;

int main() {
    int N;
    cin >> N;
    vector<long long> fib(N + 1);
    fib[0] = 0;
    if (N > 0) fib[1] = 1;
    for (int i = 2; i <= N; ++i) {
        fib[i] = fib[i-1] + fib[i-2];
    }
    cout << fib[N] << endl;
    return 0;
}
