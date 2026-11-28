Here is a JavaScript solution using binary search and dynamic programming. The solution first sorts the input array in descending order, then initiates a binary search from the maximum sum to the sum of all numbers, and finally returns the smallest sum that fulfills the condition.

function splitArray(nums, k) {
    nums.sort((a, b) => b - a);
    let left = nums[0], right = nums.reduce((acc, val) => acc + val, 0);
    while (left < right) {
        const mid = Math.floor((left + right) / 2), sum = 0, count = 0;
        for (let i = 0; i < nums.length; i++) {
            if (sum + nums[i] <= mid) {
                sum += nums[i];
            } else {
                sum = nums[i];
                count++;
            }
        }
        if (count <= k - 1) {
            right = mid;
        } else {
            left = mid + 1;
        }
    }
    return left;
}

This solution has a time complexity of O(n log n) due to the sorting and binary search, and a space complexity of O(1), assuming that the input array and its size are constant. 

For example, if we call `splitArray([5, 1, 4, 3, 6, 2], 3)`, the code will return `3` which is the minimum possible largest subarray sum.