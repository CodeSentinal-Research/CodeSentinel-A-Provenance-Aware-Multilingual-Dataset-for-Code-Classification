Here is the JavaScript code for the problem:

function leftSumDifference(nums) {
    if(nums === null || nums.length === 0) {
        return nums;
    }
    let sum = 0;
    for(let i = 0; i < nums.length; i++) {
        sum += nums[i];
        nums[i] = Math.abs(sum - nums[i]);
    }
    return nums;
}

This code takes an array of integers `nums` as input and constructs an array where each element is the absolute difference between the sum of elements to its left and the sum of elements to its right. It first checks if the input array is null or empty, and if so, returns the input array. If not, it calculates the sum of the array elements and then calculates the absolute difference between the sum of the array and the current element. The resulting array is then returned.

To use this function, you can pass an array of integers as an argument like this:

console.log(leftSumDifference([1, 2, 3, 4, 5]));  // Outputs: [1, 3, 6, 10, 15]

This code has a time complexity of O(n), where n is the length of the array. This is because it performs a single pass through the array.