#include <iostream>
using namespace std;

long long catalan(int n) {
    long long res = 1;
    if (n == 0 || n == 1) return res;
    for (int i = 1; i <= n; i++) {
        res *= (n + 1 - i);
        res /= i;
    }
    return res;
}

int main() {
    int n;
    cout << "Enter the value of n: ";
    cin >> n;
    cout << "The " << n << "th Catalan number is " << catalan(n);
    return 0;
}