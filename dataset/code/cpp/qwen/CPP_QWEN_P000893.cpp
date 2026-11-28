#include <iostream>
#include <vector>
#include <set>
using namespace std;

int main() {
    long long N;
    cin >> N;
    set<long long> factors;
    for (long long i = 2; i * i <= N; ++i) {
        if (N % i == 0) {
            factors.insert(i);
            while (N % i == 0) N /= i;
        }
    }
    if (N > 1) factors.insert(N);
    
    for (long long f : factors) {
        cout << f << " ";
    }
    cout << endl;
    return 0;
}
