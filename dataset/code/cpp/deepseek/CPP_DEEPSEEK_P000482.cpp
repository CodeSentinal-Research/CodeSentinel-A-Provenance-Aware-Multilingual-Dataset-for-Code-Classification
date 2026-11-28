#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
    unordered_map<int, int> m;
    for(int i = 0; i < nums2.size(); i++) {
        m[nums2[i]] = i;
    }

    for(int i = 0; i < nums1.size(); i++) {
        nums1[i] = m[nums1[i]];
    }

    return nums1;
}

int main() {
    vector<int> nums1 = {4,1,2};
    vector<int> nums2 = {1,3,4,2};

    nums1 = nextGreaterElement(nums1, nums2);

    for(int i = 0; i < nums1.size(); i++) {
        cout << nums1[i] << " ";
    }

    return 0;
}