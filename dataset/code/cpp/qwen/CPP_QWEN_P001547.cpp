#include <iostream>
#include <vector>
using namespace std;

int main() {
    int n, k;
    cin >> n >> k;
    vector<int> nums(n);
    for (int i = 0; i < n; ++i) cin >> nums[i];
    
    int maxOdds = 0;
    int currentOdds = 0;
    
    for (int i = 0; i < k; ++i) {
        if (nums[i] % 2 != 0) currentOdds++;
    }
    maxOdds = currentOdds;
    
    for (int i = k; i < n; ++i) {
        if (nums[i] % 2 != 0) currentOdds++;
        if (nums[i-k] % 2 != 0) currentOdds--;
        maxOdds = max(maxOdds, currentOdds);
    }
    
    cout << maxOdds << endl;
    return 0;
}
