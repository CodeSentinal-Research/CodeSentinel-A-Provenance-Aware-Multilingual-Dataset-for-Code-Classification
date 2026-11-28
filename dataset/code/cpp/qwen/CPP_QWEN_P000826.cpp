#include <iostream>
using namespace std;

int main() {
    long long n;
    cin >> n;
    
    long long low = 1, high = n;
    long long res = 0;
    while (low <= high) {
        long long mid = low + (high - low) / 2;
        long long coinsNeeded = mid * (mid + 1) / 2;
        if (coinsNeeded <= n) {
            res = mid;
            low = mid + 1;
        } else {
            high = mid - 1;
        }
    }
    cout << res << endl;
    return 0;
}
