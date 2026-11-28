#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int findUnsortedSubarray(vector<int>& nums) {
    vector<int> nums_copy(nums);
    sort(nums_copy.begin(), nums_copy.end());
    int start = -1, end = -2;
    for (int i = 0; i < nums.size(); ++i) {
        if (nums[i] != nums_copy[i]) {
            if (start == -1) start = i;
            end = i;
        }
    }
    return end - start + 1;
}

int main() {
    vector<int> nums = {2, 3, 4, 5, 7, 10, 9, 14, 13};
    int result = findUnsortedSubarray(nums);
    cout << result << endl;
    return 0;
}