#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int findUnsortedSubarray(vector<int>& nums) {
    vector<int> sortedNums(nums);
    sort(sortedNums.begin(), sortedNums.end());

    int start = -1, end = -2;
    for (int i = 0; i < nums.size(); ++i) {
        if (nums[i] != sortedNums[i]) {
            if (start == -1) start = i;
            end = i;
        }
    }

    if (start == -1) return 0;
    return end - start + 1;
}

int main() {
    int N;
    cin >> N;
    vector<int> nums(N);
    for (int i = 0; i < N; ++i) {
        cin >> nums[i];
    }

    int result = findUnsortedSubarray(nums);
    cout << result;

    return 0;
}