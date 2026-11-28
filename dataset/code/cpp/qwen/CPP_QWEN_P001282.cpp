#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// Helper to create max number of length k from nums
vector<int> maxNumberFromOneArray(const vector<int>& nums, int k) {
    int drop = nums.size() - k;
    vector<int> res;
    for (int num : nums) {
        while (drop > 0 && !res.empty() && res.back() < num) {
            res.pop_back();
            drop--;
        }
        res.push_back(num);
    }
    res.resize(k);
    return res;
}

// Merge two arrays to form max number
vector<int> merge(const vector<int>& nums1, const vector<int>& nums2) {
    vector<int> res;
    auto it1 = nums1.begin(), it2 = nums2.begin();
    while (it1 != nums1.end() || it2 != nums2.end()) {
        if (lexicographical_compare(it1, nums1.end(), it2, nums2.end())) {
            res.push_back(*it2++);
        } else {
            res.push_back(*it1++);
        }
    }
    return res;
}

int main() {
    int n, m, k;
    cin >> n >> m >> k;
    vector<int> nums1(n), nums2(m);
    for (int i = 0; i < n; ++i) cin >> nums1[i];
    for (int i = 0; i < m; ++i) cin >> nums2[i];
    
    vector<int> maxRes;
    for (int i = max(0, k - m); i <= min(k, n); ++i) {
        auto v1 = maxNumberFromOneArray(nums1, i);
        auto v2 = maxNumberFromOneArray(nums2, k - i);
        auto merged = merge(v1, v2);
        if (lexicographical_compare(maxRes.begin(), maxRes.end(), merged.begin(), merged.end())) {
            maxRes = merged;
        }
    }
    
    for (int num : maxRes) cout << num;
    cout << endl;
    
    return 0;
}
