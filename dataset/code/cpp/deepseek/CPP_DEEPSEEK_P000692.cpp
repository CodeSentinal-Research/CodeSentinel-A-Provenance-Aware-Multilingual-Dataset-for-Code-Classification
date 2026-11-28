#include <iostream>
#include <vector>

using namespace std;

bool isSorted(vector<int>& nums, int index = 0) {
    if (index == nums.size() - 1) {
        return true;
    }

    if (nums[index] > nums[index + 1]) {
        return false;
    }

    return isSorted(nums, index + 1);
}

int main() {
    vector<int> nums = {1, 2, 3, 4, 5};
    if (isSorted(nums)) {
        cout << "The array is sorted." << endl;
    } else {
        cout << "The array is not sorted." << endl;
    }
    return 0;
}