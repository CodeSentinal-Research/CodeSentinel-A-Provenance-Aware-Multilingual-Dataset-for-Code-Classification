#include <iostream>
#include <vector>
using namespace std;

int findMin(vector<int>& nums, int start, int end) {
    if (start == end) {
        return nums[start];
    } else {
        int mid = (start + end) / 2;
        int leftMin = findMin(nums, start, mid);
        int rightMin = findMin(nums, mid + 1, end);
        return min(leftMin, rightMin);
    }
}

int main() {
    int n;
    cin >> n;
    vector<int> nums(n);
    for (int i = 0; i < n; i++) {
        cin >> nums[i];
    }
    int minElement = findMin(nums, 0, n - 1);
    cout << minElement;
    return 0;
}