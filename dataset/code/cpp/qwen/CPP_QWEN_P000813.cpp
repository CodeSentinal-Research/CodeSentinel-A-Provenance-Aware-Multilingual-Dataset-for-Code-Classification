#include <iostream>
using namespace std;

int main() {
    long long x;
    cin >> x;
    
    if (x == 0) {
        cout << 0 << endl;
        return 0;
    }

    long long low = 1, high = x, res = 0;
    while (low <= high) {
        long long mid = low + (high - low) / 2;
        if (mid <= x / mid) { // Avoid overflow
            res = mid;
            low = mid + 1;
        } else {
            high = mid - 1;
        }
    }
    
    cout << res << endl;
    return 0;
}
