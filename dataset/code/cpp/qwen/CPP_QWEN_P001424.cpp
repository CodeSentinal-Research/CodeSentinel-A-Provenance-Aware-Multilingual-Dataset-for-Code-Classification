#include <iostream>
#include <vector>
#include <unordered_map>
#include <unordered_set>
using namespace std;

int main() {
    int n;
    cin >> n;
    vector<int> nums(n);
    for (int i = 0; i < n; ++i) cin >> nums[i];
    
    unordered_map<int, int> freq;
    for (int num : nums) freq[num]++;
    
    unordered_set<int> counts;
    bool unique = true;
    for (auto& p : freq) {
        if (counts.count(p.second)) {
            unique = false;
            break;
        }
        counts.insert(p.second);
    }
    
    cout << (unique ? "YES" : "NO") << endl;
    return 0;
}
