#include <iostream>
using namespace std;

int main() {
    long long dividend, divisor;
    cin >> dividend >> divisor;
    
    if (dividend == INT_MIN && divisor == -1) return INT_MAX;
    
    bool negative = (dividend < 0) ^ (divisor < 0);
    long long ldividend = labs(dividend);
    long long ldivisor = labs(divisor);
    
    long long quotient = 0;
    for (int i = 31; i >= 0; --i) {
        if ((ldividend >> i) >= ldivisor) {
            quotient += (1LL << i);
            ldividend -= (ldivisor << i);
        }
    }
    
    if (negative) quotient = -quotient;
    cout << quotient << endl;
    return 0;
}
