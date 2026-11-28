#include <iostream>
#include <vector>

int findPeakElement(std::vector<int>& nums) {
    int left = 0;
    int right = nums.size() - 1;
    
    while(left < right) {
        int mid = (left + right) / 2;
        
        if(nums[mid] > nums[mid + 1]) {
            right = mid;
        } else {
            left = mid + 1;
        }
    }
    
    return left;
}

int main() {
    std::vector<int> nums = {1, 2, 3, 5, 4, 3, 2, 1};
    
    std::cout << "Peak element is at index: " << findPeakElement(nums) << std::endl;
    
    return 0;
}

The code above uses a binary search approach to find the peak element. It works by checking the middle element and comparing it with the adjacent elements. If the middle element is greater than both adjacent elements, it means that the peak element is on the right side of the middle element. If not, it means that the peak element is on the left side of the middle element. We then adjust our search space by reducing the right boundary to mid and continue the process. This process is repeated until we find the peak element.