Here is the code for the problem:

function findMin(nums) {
    let left = 0;
    let right = nums.length - 1;

    while (left < right) {
        const mid = Math.floor((left + right) / 2);

        if (nums[mid] > nums[right]) {
            left = mid + 1;
        } else {
            right = mid;
        }
    }

    return nums[left];
}

This function uses binary search to find the minimum element in the rotated sorted array. The function assumes that the array is sorted in ascending order and rotated at some point. It starts by initializing two pointers, `left` and `right`, to the start and end of the array respectively. It then enters a loop where it calculates the middle index, and checks if the middle element is greater than the right element. If it is, it means that the minimum element is on the right side of the midpoint, and so it moves the left pointer to one position to the right of the midpoint. If the middle element is not greater than the right element, it means that the minimum element is in the left side of the midpoint, so it moves the right pointer to the midpoint. It continues until the left pointer is no longer greater than the right pointer, at which point it returns the value of the left pointer as the minimum element.