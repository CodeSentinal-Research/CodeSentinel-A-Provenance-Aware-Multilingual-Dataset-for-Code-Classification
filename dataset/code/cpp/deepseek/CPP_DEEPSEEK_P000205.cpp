#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int findMedian(vector<int> &nums1, vector<int> &nums2) {
    vector<int> merged;
    merged.reserve(nums1.size() + nums2.size());
    merge(nums1.begin(), nums1.end(), nums2.begin(), nums2.end(), back_inserter(merged));

    int size = merged.size();
    if (size % 2 == 0) {
        return (merged[size / 2 - 1] + merged[size / 2]) / 2;
    } else {
        return merged[size / 2];
    }
}

int main() {
    int N;
    cin >> N;
    vector<int> nums1(N), nums2(N);
    for (int i = 0; i < N; i++) {
        cin >> nums1[i];
    }
    for (int i = 0; i < N; i++) {
        cin >> nums2[i];
    }
    cout << findMedian(nums1, nums2) << endl;
    return 0;
}