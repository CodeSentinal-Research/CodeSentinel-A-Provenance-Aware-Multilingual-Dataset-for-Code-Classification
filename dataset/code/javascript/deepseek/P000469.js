Here's the code for the problem:

function searchRange(nums, target) {
    let low = -1, high = -1;
    let left = 0, right = nums.length - 1;
    
    while(left <= right){
        if(nums[left] === target && nums[right] === target){
            low = left;
            high = right;
            break;
        }
        if(nums[left] === target){
            high = left;
            left++;
        }
        if(nums[right] === target){
            low = right;
            right--;
        }
    }
    
    return low === -1 && high === -1 ? [-1, -1] : [low, high];
}

// Test the function
console.log(searchRange([5, 7, 7, 8, 8, 10], 8)); // [3, 4]
console.log(searchRange([1, 2, 3, 4, 5, 6], 5)); // [4, 4]
console.log(searchRange([1, 2, 3, 4, 5, 6], 7)); // [-1, -1]

In this solution, we initialize two pointers, `left` and `right`, at the ends of the array. We then use a while loop to continue shifting the pointers until we find both the smallest and the largest indices of `target` in the array. If `target` is found at `left` or `right`, we shift the corresponding pointer. If `target` is not found, we return `[-1, -1]` as the answer.