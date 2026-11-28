Here is a JavaScript code that generates all possible subsets of an array and returns the subset sums in non-decreasing order.

function findSubsets(nums, index, currentSum, currentSet, sums) {
    // If we reached the end of the array, add the current sum to the results
    if (index === nums.length) {
        sums.push(currentSum);
        return;
    }

    // Include the current number in the current subset
    findSubsets(nums, index + 1, currentSum + nums[index], currentSet, sums);

    // Exclude the current number from the current subset
    findSubsets(nums, index + 1, currentSum, currentSet, sums);
}

function getAllSubsets(nums) {
    // Initialize the sums array
    let sums = [];

    // Call the helper function
    findSubsets(nums, 0, 0, [], sums);

    // Sort the sums array in non-decreasing order
    sums.sort((a, b) => a - b);

    return sums;
}

let nums = [1, 2, 3, 4];
console.log(getAllSubsets(nums));

This code uses recursion to generate all subsets of the input array. It takes three parameters: the current index in the array, the current sum, the current subset, and the array of sums.

The `findSubsets` function recursively generates all subsets by two cases: including the current number (which means we should add it to the current subset) and excluding the current number (which means we shouldn't add it to the current subset). 

The `getAllSubsets` function calls `findSubsets` to generate all subsets and finally sorts the sums array in non-decreasing order. 

The input for this code is an array of integers.