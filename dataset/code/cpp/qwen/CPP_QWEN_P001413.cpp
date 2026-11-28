#include <iostream>
#include <vector>
#include <unordered_map>
#include <climits>
using namespace std;

int main() {
    int n;
    cin >> n;
    vector<int> nums(n);
    for (int i = 0; i < n; ++i) cin >> nums[i];
    
    unordered_map<int, int> freq;
    for (int num : nums) freq[num]++;
    
    int maxUnique = INT_MIN;
    bool found = false;
    for (auto& p : freq) {
        if (p.second == 1) {
            found = true;
            maxUnique = max(maxUnique, p.first);
        }
    }
    
    if (!found) cout << -1 << endl;
    else cout << maxUnique << endl;
    
    return 0;
}
