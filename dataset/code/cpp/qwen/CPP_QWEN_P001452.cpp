#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

int main() {
    int n, q;
    cin >> n >> q;
    vector<int> nums(n);
    for (int i = 0; i < n; ++i) cin >> nums[i];
    
    unordered_map<int, int> freq;
    for (int num : nums) freq[num]++;
    
    while (q--) {
        int idx, val;
        cin >> idx >> val;
        
        // Update frequency
        freq[nums[idx]]--;
        if (freq[nums[idx]] == 0) freq.erase(nums[idx]);
        
        nums[idx] = val;
        freq[val]++;
        
        cout << freq.size() << endl;
    }
    
    return 0;
}
