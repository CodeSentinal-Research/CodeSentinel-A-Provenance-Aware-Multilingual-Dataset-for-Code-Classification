function minimumSumSubarray(k, arr) {
    let curSum = 0;
    for (let i = 0; i < k; i++) curSum += arr[i];
    let minSum = curSum;

    for (let i = k; i < arr.length; i++) {
        curSum += arr[i] - arr[i - k];
        if (curSum < minSum) minSum = curSum;
    }
    return minSum;
}

module.exports = { minimumSumSubarray };