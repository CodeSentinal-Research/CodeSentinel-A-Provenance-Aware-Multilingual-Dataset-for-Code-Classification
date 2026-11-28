#include <iostream>
using namespace std;

// Simulated API
int pick;
int guess(int num) {
    if (num == pick) return 0;
    if (num < pick) return 1;
    return -1;
}

int main() {
    int n;
    cin >> n >> pick; // In real problem, pick is hidden. Here we read it for simulation.
    
    int low = 1, high = n;
    while (low <= high) {
        int mid = low + (high - low) / 2;
        int res = guess(mid);
        if (res == 0) {
            cout << mid << endl;
            return 0;
        } else if (res == 1) {
            low = mid + 1;
        } else {
            high = mid - 1;
        }
    }
    return 0;
}
