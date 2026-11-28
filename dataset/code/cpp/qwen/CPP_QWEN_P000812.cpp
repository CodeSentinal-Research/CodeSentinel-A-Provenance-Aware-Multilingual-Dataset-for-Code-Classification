#include <iostream>
using namespace std;

int main() {
    long long num;
    cin >> num;
    
    long long low = 1, high = num;
    bool isSquare = false;
    while (low <= high) {
        long long mid = low + (high - low) / 2;
        if (mid * mid == num) {
            isSquare = true;
            break;
        } else if (mid * mid < num) {
            low = mid + 1;
        } else {
            high = mid - 1;
        }
    }
    
    cout << (isSquare ? "true" : "false") << endl;
    return 0;
}
