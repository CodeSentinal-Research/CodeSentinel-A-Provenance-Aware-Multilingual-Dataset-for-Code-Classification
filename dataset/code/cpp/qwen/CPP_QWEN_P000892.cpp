#include <iostream>
#include <vector>
using namespace std;

int main() {
    long long N;
    cin >> N;
    vector<long long> factors;
    for (long long i = 2; i * i <= N; ++i) {
        while (N % i == 0) {
            factors.push_back(i);
            N /= i;
        }
    }
    if (N > 1) factors.push_back(N);
    
    for (size_t i = 0; i < factors.size(); ++i) {
        if (i > 0) cout << " ";
        cout << factors[i];
    }
    cout << endl;
    return 0;
}
