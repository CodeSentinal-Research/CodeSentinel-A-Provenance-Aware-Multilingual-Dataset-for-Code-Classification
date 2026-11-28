#include <iostream>
using namespace std;

long long digitSum(long long n) {
    long long s = 0;
    while (n > 0) {
        s += n % 10;
        n /= 10;
    }
    return s;
}

// Efficient calculation for range [0, N]
long long sumDigitsUpTo(long long n) {
    if (n < 0) return 0;
    if (n < 10) return n * (n + 1) / 2;
    
    long long p = 1;
    while (p * 10 <= n) p *= 10;
    
    long long msd = n / p;
    long long remainder = n % p;
    
    // Sum of digits from 0 to p-1 is 45 * (p/10) * log10(p) ? 
    // Formula: sum(0 to 10^k - 1) = k * 45 * 10^(k-1)
    long long k = 0;
    long long temp = p;
    while (temp > 1) { k++; temp /= 10; }
    
    long long sumP = k * 45 * (p / 10); 
    
    long long res = msd * sumP + (msd * (msd - 1) / 2) * p + msd * (remainder + 1) + sumDigitsUpTo(remainder);
    return res;
}

int main() {
    long long L, R;
    cin >> L >> R;
    cout << sumDigitsUpTo(R) - sumDigitsUpTo(L - 1) << endl;
    return 0;
}
