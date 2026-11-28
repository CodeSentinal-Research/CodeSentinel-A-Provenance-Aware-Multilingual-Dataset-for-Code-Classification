#include <iostream>
using namespace std;

int singleNonDuplicate(vector<int>& nums) {
    int low = 0;
    int high = nums.size()-1;

    while(low < high) {
        int mid = (low + high) / 2;
        if(mid % 2 == 0) {
            if(nums[mid] == nums[mid+1])
                low = mid + 1;
            else if(nums[mid-1] == nums[mid])
                high = mid - 1;
            else 
                return nums[mid];
        } else {
            if(nums[mid] == nums[mid+1])
                high = mid - 1;
            else if(nums[mid-1] == nums[mid])
                low = mid + 1;
            else 
                return nums[mid];
        }
    }
    return low;
}

int main() {
    vector<int> nums;
    cout << singleNonDuplicate(nums);
    return 0;
}