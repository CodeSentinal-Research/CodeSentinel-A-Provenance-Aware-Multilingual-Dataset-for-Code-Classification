#include <iostream>
#include <vector>
using namespace std;

int main() {
    int n;
    cin >> n;
    vector<int> seats(n);
    for (int i = 0; i < n; ++i) cin >> seats[i];
    
    int maxDist = 0;
    int lastOccupied = -1;
    
    // Check distance from start to first occupied
    for (int i = 0; i < n; ++i) {
        if (seats[i] == 1) {
            maxDist = i;
            lastOccupied = i;
            break;
        }
    }
    
    // Check distances between occupied seats
    for (int i = lastOccupied + 1; i < n; ++i) {
        if (seats[i] == 1) {
            maxDist = max(maxDist, (i - lastOccupied) / 2);
            lastOccupied = i;
        }
    }
    
    // Check distance from last occupied to end
    if (lastOccupied != -1) {
        maxDist = max(maxDist, n - 1 - lastOccupied);
    } else {
        // If no one is seated, distance is technically undefined or n, but problem implies at least one person usually.
        // If empty, max dist to closest person is infinite/undefined. Assuming at least one 1 based on constraints logic usually.
        // If all 0, return n? Or 0? Let's assume valid input with at least one 1.
    }
    
    cout << maxDist << endl;
    return 0;
}
