#include <iostream>
#include <vector>
#include <set>
using namespace std;

int main() {
    int n, limit;
    cin >> n >> limit;
    vector<int> nums(n);
    for (int i = 0; i < n; ++i) cin >> nums[i];
    
    multiset<int> window;
    int left = 0;
    int maxLen = 0;
    
    for (int right = 0; right < n; ++right) {
        window.insert(nums[right]);
        
        while (*window.rbegin() - *window.begin() > limit) {
            window.erase(window.find(nums[left]));
            left++;
        }
        
        maxLen = max(maxLen, right - left + 1);
    }
    
    cout << maxLen << endl;
    return 0;
}
