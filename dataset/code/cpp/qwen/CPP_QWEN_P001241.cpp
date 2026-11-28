#include <iostream>
#include <vector>
using namespace std;

int main() {
    int n;
    cin >> n;
    vector<int> gas(n), cost(n);
    for (int i = 0; i < n; ++i) cin >> gas[i];
    for (int i = 0; i < n; ++i) cin >> cost[i];
    
    int totalTank = 0, currTank = 0, start = 0;
    for (int i = 0; i < n; ++i) {
        totalTank += gas[i] - cost[i];
        currTank += gas[i] - cost[i];
        if (currTank < 0) {
            start = i + 1;
            currTank = 0;
        }
    }
    
    cout << (totalTank >= 0 ? start : -1) << endl;
    return 0;
}
