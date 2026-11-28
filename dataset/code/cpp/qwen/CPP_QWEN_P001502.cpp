#include <iostream>
#include <vector>
using namespace std;

int main() {
    int n;
    cin >> n;
    vector<int> nums(n);
    int ones = 0;
    for (int i = 0; i < n; ++i) {
        cin >> nums[i];
        if (nums[i] == 1) ones++;
    }
    
    if (ones == 0) {
        cout << 0 << endl;
        return 0;
    }
    
    // Sliding window of size 'ones' to find max ones in window
    // Min swaps = ones - max_ones_in_window
    int maxOnesInWindow = 0;
    int currentOnes = 0;
    
    for (int i = 0; i < ones; ++i) {
        if (nums[i] == 1) currentOnes++;
    }
    maxOnesInWindow = currentOnes;
    
    for (int i = ones; i < n; ++i) {
        if (nums[i] == 1) currentOnes++;
        if (nums[i - ones] == 1) currentOnes--;
        maxOnesInWindow = max(maxOnesInWindow, currentOnes);
    }
    
    cout << ones - maxOnesInWindow << endl;
    return 0;
}
