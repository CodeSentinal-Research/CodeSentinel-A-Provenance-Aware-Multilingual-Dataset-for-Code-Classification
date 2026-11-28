Here is the JavaScript code for the problem:

function findMaxAverage(nums, k) {
    if (!Array.isArray(nums) || !Number.isInteger(k) || k < 1 || k > nums.length || nums.length < 1) {
        throw new Error('Invalid input');
    }

    let maxAverage = -Infinity;
    for (let i = 0; i <= nums.length - k; i++) {
        let sum = 0;
        for (let j = i; j < i + k; j++) {
            sum += nums[j];
        }
        maxAverage = Math.max(maxAverage, sum / k);
    }
    return maxAverage;
}

In the code above, we first check if the input is valid. Then we initialize maxAverage to -Infinity. For each subarray of size k, we calculate the sum of its elements and update maxAverage if the sum is greater than the current maxAverage. This process is repeated for all subarrays of size k. The maximum average is then returned as the result.