function maximumSumSubarray(k, arr) {
    let curSum = 0;
    for (let i = 0; i < k; i++) curSum += arr[i];
    let maxSum = curSum;

    for (let i = k; i < arr.length; i++) {
        curSum += arr[i] - arr[i - k];
        if (curSum > maxSum) maxSum = curSum;
    }
    return maxSum;
}

module.exports = { maximumSumSubarray };