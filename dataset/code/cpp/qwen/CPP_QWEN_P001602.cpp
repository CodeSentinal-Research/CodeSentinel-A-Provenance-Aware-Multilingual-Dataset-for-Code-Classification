#include <iostream>
#include <vector>
#include <climits>
#include <cmath>
using namespace std;

int main() {
    int n;
    cin >> n;
    vector<long long> nums(n);
    for (int i = 0; i < n; ++i) cin >> nums[i];
    
    long long maxAbs = 0;
    long long currentSum = 0;
    for (int i = 0; i < n; ++i) {
        currentSum += nums[i];
        if (abs(currentSum) > maxAbs) {
            maxAbs = abs(currentSum);
        }
    }
    
    cout << maxAbs << endl;
    return 0;
}
