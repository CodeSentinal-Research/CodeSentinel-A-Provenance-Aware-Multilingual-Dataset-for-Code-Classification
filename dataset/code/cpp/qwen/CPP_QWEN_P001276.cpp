#include <iostream>
#include <vector>
#include <climits>
using namespace std;

int main() {
    int n;
    cin >> n;
    vector<int> seats(n);
    for (int i = 0; i < n; ++i) cin >> seats[i];
    
    int maxDist = 0;
    int lastOccupied = -1;
    
    for (int i = 0; i < n; ++i) {
        if (seats[i] == 1) {
            if (lastOccupied == -1) {
                maxDist = i;
            } else {
                maxDist = max(maxDist, (i - lastOccupied) / 2);
            }
            lastOccupied = i;
        }
    }
    
    if (lastOccupied != -1) {
        maxDist = max(maxDist, n - 1 - lastOccupied);
    }
    
    cout << maxDist << endl;
    return 0;
}
