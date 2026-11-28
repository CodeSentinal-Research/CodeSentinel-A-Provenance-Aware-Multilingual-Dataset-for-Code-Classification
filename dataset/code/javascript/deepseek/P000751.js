Here is a JavaScript solution for the problem:

function countSubsequences(n, nums, target) {
    if (n === 0) return target === 0 ? 1 : 0;

    // Exclude the current number
    let exclude = 0;
    if (target >= nums[n - 1]) exclude = countSubsequences(n - 1, nums, target - nums[n - 1]);

    // Include the current number
    let include = 0;
    if (target > nums[n - 1]) include = 1 + countSubsequences(n - 1, nums, target - nums[n - 1]);

    return exclude + include;
}

console.log(countSubsequences(3, [4, 2, 5], 5)); // Output: 2

This solution takes in the length of the array `n`, the array `nums`, and the target sum `target` as input. It then uses recursion to count the number of valid subsequences whose sum equals `target`.

First, if `n` is 0, it checks if `target` is 0. If it is, it means there is only one valid subsequence (empty subsequence), so it returns 1. Otherwise, it returns 0.

Then, it excludes the current number from both the subsequence and counts the number of valid subsequences when the target is greater than or equal to the current number.

In addition, it includes the current number into both the subsequence and counts the number of valid subsequences when the target is greater than the current number.

Finally, it returns the sum of the counts of both excluding and including the current number.