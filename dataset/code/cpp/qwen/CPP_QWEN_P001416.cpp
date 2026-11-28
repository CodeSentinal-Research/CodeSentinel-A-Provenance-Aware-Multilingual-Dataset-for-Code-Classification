#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>
using namespace std;

int main() {
    int n;
    cin >> n;
    vector<int> nums(n);
    for (int i = 0; i < n; ++i) cin >> nums[i];
    
    unordered_map<int, int> freq;
    for (int num : nums) freq[num]++;
    
    int maxLen = 0;
    for (auto& p : freq) {
        if (freq.find(p.first + 1) != freq.end()) {
            maxLen = max(maxLen, p.second + freq[p.first + 1]);
        }
    }
    
    cout << maxLen << endl;
    return 0;
}
