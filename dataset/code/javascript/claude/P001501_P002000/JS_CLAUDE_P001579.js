function maxSlidingWindowSum(arr, k) {
    let sum = 0, maxSum;
    for (let i = 0; i < k; i++) sum += arr[i];
    maxSum = sum;
    for (let i = k; i < arr.length; i++) {
        sum += arr[i] - arr[i - k];
        maxSum = Math.max(maxSum, sum);
    }
    return maxSum;
}

module.exports = { maxSlidingWindowSum };
