function wiggleSubsequence(arr) {
    let dp = [];
    let dpNegative = [];
    dpNegative[0] = arr[0];

    for (let i = 1; i < arr.length; i++) {
        dp[i] = arr[i];
        dpNegative[i] = arr[i];

        if (arr[i] > arr[i - 1]) {
            dp[i] = Math.max(dp[i], dpNegative[i - 1] + arr[i]);
            dpNegative[i] = Math.min(dpNegative[i], dp[i - 1] + arr[i]);
        } else {
            dpNegative[i] = Math.max(dpNegative[i], dp[i - 1] + arr[i]);
            dp[i] = Math.min(dp[i], dpNegative[i - 1] + arr[i]);
       
        }
    }
    return Math.max(...dp, ...dpNegative);
}