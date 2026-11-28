#include <iostream>
#include <vector>
#include <unordered_set>
using namespace std;

int main() {
    int n, k;
    cin >> n >> k;
    vector<int> nums(n);
    for (int i = 0; i < n; ++i) cin >> nums[i];
    
    int count = 0;
    
    for (int i = 0; i <= n - k; ++i) {
        unordered_set<int> windowSet;
        bool distinct = true;
        for (int j = i; j < i + k; ++j) {
            if (windowSet.find(nums[j]) != windowSet.end()) {
                distinct = false;
                break;
            }
            windowSet.insert(nums[j]);
        }
        if (distinct) count++;
    }
    
    cout << count << endl;
    return 0;
}
