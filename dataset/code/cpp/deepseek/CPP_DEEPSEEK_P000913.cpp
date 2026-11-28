#include <iostream>
using namespace std;

int main() {
    int n, r, P;
    cout << "Enter the value of n: ";
    cin >> n;
    cout << "Enter the value of r: ";
    cin >> r;
    cout << "Enter the value of P: ";
    cin >> P;
    
    if (r > n) {
        cout << "r cannot be greater than n";
        return 0;
    }
    
    long long fact[1000000] = {1};
    long long rfact[1000000] = {1};
    long long nrfact[1000000] = {1};
    
    for (int i = 1; i <= n; i++) {
        fact[i] = (fact[i - 1] * i) % P;
        rfact[i] = (rfact[i - 1] * (fact[i])) % P;
        nrfact[i] = (nrfact[i - 1] * (fact[i] * fact[i - r])) % P;
    }
    
    long long nCr = (rfact[n] * nrfact[n - r]) % P;
    
    cout << "nCr mod P = " << nCr << endl;
    
    return 0;
}