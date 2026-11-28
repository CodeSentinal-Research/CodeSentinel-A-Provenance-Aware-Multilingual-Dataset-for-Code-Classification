Here is the JavaScript code for the problem:

function searchInsert(nums, target) {
    for(let i = 0; i < nums.length; i++) {
        if(nums[i] >= target) {
            return i;
        }
    }
    return nums.length;
}

This function takes in two parameters: a sorted array of integers `nums` and a target integer `target`. It iterates over the array and returns the index where `target` should be inserted. If `target` is larger than the largest number in the array, it should be inserted at the end of the array.