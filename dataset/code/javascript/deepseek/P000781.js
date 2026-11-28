Here is the JavaScript code for the problem:

function runningSum(nums) {
    for(let i = 1; i < nums.length; i++) {
        nums[i] += nums[i - 1];
    }
    return nums;
}

In this code, the function 'runningSum' accepts an array 'nums' as an argument. It then iterates over the array and for each element at index 'i', it adds the current element to the element at index 'i - 1' (which is the sum of the previous elements in the array). It then returns the updated array.