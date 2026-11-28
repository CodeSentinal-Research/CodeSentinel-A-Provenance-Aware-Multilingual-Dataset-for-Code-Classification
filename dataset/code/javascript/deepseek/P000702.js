Here is the JavaScript code for the problem:

function countOccurrences(nums, target) {
    if (nums.length === 0) {
        return 0;
    }
    if (nums[0] === target) {
        return 1 + countOccurrences(nums.slice(1), target);
    } else {
        return countOccurrences(nums.slice(1), target);
    }
}

// Testing the function
console.log(countOccurrences([1, 2, 3, 4, 2, 2, 3, 4, 4, 2, 5], 2)); // Output: 3

This function uses recursion to traverse the array and count the occurrences of the target. If the current element in the array is the target, it increments the count and calls the function again on the rest of the array (excluding the first element). If it is not the target, it calls the function again on the rest of the array (excluding the first element). The function will return the total count of the target.