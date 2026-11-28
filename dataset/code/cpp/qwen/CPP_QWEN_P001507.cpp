#include <iostream>
#include <vector>
using namespace std;

int main() {
    int n;
    cin >> n;
    vector<int> nums(n);
    for (int i = 0; i < n; ++i) cin >> nums[i];
    
    if (n < 2) {
        cout << n << endl;
        return 0;
    }
    
    int maxLen = 1;
    int currLen = 1;
    // State: 0=init, 1=up, 2=down
    int state = 0; 
    
    for (int i = 1; i < n; ++i) {
        if (nums[i] > nums[i-1]) {
            if (state == 0 || state == 2) {
                state = 1;
                currLen++;
            } else if (state == 1) {
                currLen = 2; // Reset, start new turbulent subarray
            }
        } else if (nums[i] < nums[i-1]) {
            if (state == 0 || state == 1) {
                state = 2;
                currLen++;
            } else if (state == 2) {
                currLen = 2;
            }
        } else {
            currLen = 1;
            state = 0;
        }
        maxLen = max(maxLen, currLen);
    }
    
    cout << maxLen << endl;
    return 0;
}
