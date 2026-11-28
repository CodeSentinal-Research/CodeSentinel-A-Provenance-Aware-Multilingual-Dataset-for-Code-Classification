#include <iostream>
#include <unordered_map>
#include <vector>
using namespace std;

bool containsNearbyDuplicate(vector<int>& nums, int k) {
    unordered_map<int, int> m;
    for (int i = 0; i < nums.size(); i++) {
        if (m.find(nums[i]) != m.end() && abs(m[nums[i]] - i) <= k) {
            return true;
        }
        m[nums[i]] = i;
    }
    return false;
}

int main() {
    int n, k;
    cin >> n >> k;
    vector<int> nums(n);
    for (int i = 0; i < n; i++) {
        cin >> nums[i];
    }
    if (containsNearbyDuplicate(nums, k)) {
        cout << "YES";
    } else {
        cout << "NO";
    }
    return 0;
}