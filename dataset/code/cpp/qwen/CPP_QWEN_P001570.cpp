#include <iostream>
#include <vector>
using namespace std;

int main() {
    int n;
    cin >> n;
    vector<int> nums(n);
    for (int i = 0; i < n; ++i) cin >> nums[i];
    
    int maxLen = 0;
    int negStart = -1;
    int lastZero = -1;
    int negCount = 0;
    
    for (int i = 0; i < n; ++i) {
        if (nums[i] < 0) {
            negCount++;
            if (negCount == 1) negStart = i;
        } else if (nums[i] == 0) {
            negCount = 0;
            lastZero = i;
            negStart = -1;
        }
        
        if (negCount % 2 == 0) {
            maxLen = max(maxLen, i - lastZero);
        } else {
            maxLen = max(maxLen, i - negStart);
        }
    }
    
    cout << maxLen << endl;
    return 0;
}
