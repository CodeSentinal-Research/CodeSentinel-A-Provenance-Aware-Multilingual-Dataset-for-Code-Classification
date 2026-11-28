function maxSumIncreasingSubseq(arr) {
    const n = arr.length;
    const dp = [...arr];
    for (let i = 1; i < n; i++) {
        for (let j = 0; j < i; j++) {
            if (arr[j] < arr[i]) dp[i] = Math.max(dp[i], dp[j] + arr[i]);
        }
    }
    return Math.max(...dp);
}

module.exports = { maxSumIncreasingSubseq };
