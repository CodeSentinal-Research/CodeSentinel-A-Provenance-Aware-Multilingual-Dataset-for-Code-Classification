#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
    vector<int> mergedVector;
    mergedVector.reserve(nums1.size() + nums2.size());
    merge(nums1.begin(), nums1.end(), nums2.begin(), nums2.end(), back_inserter(mergedVector));
    sort(mergedVector.begin(), mergedVector.end());

    int totalSize = mergedVector.size();
    if (totalSize % 2 == 0) {
        return (mergedVector[totalSize / 2 - 1] + mergedVector[totalSize / 2]) / 2.0;
    } else {
        return mergedVector[totalSize / 2];
    }
}

int main() {
    int m, n;
    cin >> m >> n;
    vector<int> nums1(m), nums2(n);
    for (int i = 0; i < m; ++i) {
        cin >> nums1[i];
    }
    for (int i = 0; i < n; ++i) {
        cin >> nums2[i];
    }
    cout << findMedianSortedArrays(nums1, nums2) << endl;
    return 0;
}