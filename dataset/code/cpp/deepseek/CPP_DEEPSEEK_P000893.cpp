#include <iostream>
#include <vector>

using namespace std;

bool isPrime(int n) {
    if (n <= 1) return false;
    if (n == 2) return true;
    if (n % 2 == 0) return false;
    for (int i = 3; i * i <= n; i += 2) {
        if (n % i == 0) return false;
    }
    return true;
}

vector<int> primeFactors(int n) {
    vector<int> factors;
    for (int i = 2; i <= n; i++) {
        if (n % i == 0 && isPrime(i)) {
            factors.push_back(i);
            while (n % i == 0) {
                n /= i;
            }
        }
    }
    return factors;
}

int main() {
    int n;
    cout << "Enter a number: ";
    cin >> n;
    if (n < 2 || n > 1000000000) {
        cout << "Invalid input, please enter a number between 2 and 10^12." << endl;
        return 0;
    }
    vector<int> factors = primeFactors(n);
    for (int factor : factors) {
        cout << factor << " ";
    }
    cout << endl;
    return 0;
}