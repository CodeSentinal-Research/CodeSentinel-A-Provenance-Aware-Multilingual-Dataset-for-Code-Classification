Here is a JavaScript function that computes the Nth Tribonacci number using dynamic programming:

function tribonacci(N) {
    if (N === 0) return 0;
    if (N === 1) return 1;
    if (N === 2) return 1;

    let dp = [0, 1, 1];

    for (let i = 3; i <= N; i++) {
        dp[i] = dp[i - 1] + dp[i - 2] + dp[i - 3];
    }

    return dp[N];
}

In this function, we initialize an array `dp` with the first three elements of the sequence, and then we compute each element by summing up the three previous elements. This approach ensures that we only calculate each element once and avoids re-computing elements.