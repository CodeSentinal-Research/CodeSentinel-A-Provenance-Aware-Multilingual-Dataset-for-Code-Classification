#include <iostream>
#include <vector>
using namespace std;

int main() {
    int n, k;
    cin >> n >> k;
    vector<int> nums(n);
    for (int i = 0; i < n; ++i) cin >> nums[i];
    
    int maxLen = 0;
    int zeros = 0;
    int left = 0;
    
    for (int right = 0; right < n; ++right) {
        if (nums[right] == 0) zeros++;
        
        while (zeros > k) {
            if (nums[left] == 0) zeros--;
            left++;
        }
        
        maxLen = max(maxLen, right - left + 1);
    }
    
    cout << maxLen << endl;
    return 0;
}
