#include <iostream>
#include <vector>
using namespace std;

vector<int> primeFactorization(int N) {
    vector<int> factors;
    for (int i = 2; i * i <= N; i++) {
        while (N % i == 0) {
            factors.push_back(i);
            N /= i;
        }
    }
    if (N > 1)
        factors.push_back(N);
    return factors;
}

int main() {
    int N;
    cout << "Enter a number: ";
    cin >> N;
    vector<int> factors = primeFactorization(N);
    for (int factor : factors) {
        cout << factor << " ";
    }
    return 0;
}