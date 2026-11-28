#include <iostream>
#include <vector>
using namespace std;

bool search(vector<int>& nums, int target) {
    int left = 0;
    int right = nums.size() - 1;
    
    while (left <= right) {
        if (nums[left] == target || nums[right] == target) {
            return true;
        }
        left++;
        right--;
    }
    
    return false;
}

int main() {
    vector<int> nums {1, 3, 1, 5, 5, 6, 7};
    int target = 5;

    cout << (search(nums, target) ? "true" : "false") << endl;

    return 0;
}