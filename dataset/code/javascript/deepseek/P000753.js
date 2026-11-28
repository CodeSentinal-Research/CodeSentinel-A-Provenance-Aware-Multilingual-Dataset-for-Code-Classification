Here is the JavaScript code:

function findSubsequences(nums, target) {
    let result = [];
    backtrack(nums, target, 0, [], result);
    return result;
}

function backtrack(nums, target, start, current, result) {
    if (current.reduce((a, b) => a + b, 0) === target && current.length > 0) {
        result.push(Array.from(current));
    }
    for (let i = start; i < nums.length; i++) {
        if (current.length === 0 || current[current.length - 1] <= nums[i]) {
            current.push(nums[i]);
            backtrack(nums, target, i + 1, current, result);
            current.pop();
        }
    }
}

console.log(findSubsequences([1, 2, 3, 4], 5));

This code first defines a function `findSubsequences` that takes the array and target as parameters. The `findSubsequences` function calls the `backtrack` function to start the process.

The `backtrack` function is a recursive function that adds numbers to a list until the sum of the list equals the target. If the list has a non-zero length and the last number in the list is less than or equal to the current number, then the current number is added to the list. If the current list has a non-zero length, it is added to the result. Finally, if the current list is not empty, the last number in the list is removed from the list. This process is repeated until the list is empty.

Finally, `findSubsequences` calls `backtrack` on the given array and target, and logs the result to the console.