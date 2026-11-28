Here is the JavaScript code that finds the peak element in an array.

function findPeakElement(nums) {
    if (nums === undefined || nums.length === 0) {
        return -1;
    }
    let left = 0;
    let right = nums.length - 1;
    while(left < right) {
        const mid = Math.floor((left + right) / 2);
        if(nums[mid] > nums[mid + 1]) {
            right = mid;
        } else {
            left = mid + 1;
        }
    }
    return left;
}

This function finds the peak element by using binary search, which has a time complexity of O(log n). The function first checks if the array is empty, and if so, it returns -1. Then, it sets the left and right pointers to the start and end of the array, and enters a while loop that continues until the left pointer is no longer less than the right pointer. In each iteration of the loop, it calculates the mid index, and checks if the element at mid + 1 is larger than the element at mid. If it is, it sets the right pointer to mid. Otherwise, it sets the left pointer to mid + 1. Finally, it returns the left pointer, which is the index of the peak element.