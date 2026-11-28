function countDistinctSubsequences(s, t) {
    const dp = Array.from(new Array(t.length + 1), () => new Array(s.length + 1).fill(0));

    for(let i = 0; i <= s.length; i++) {
        dp[0][i] = 1;
    }

    for(let i = 1; i <= t.length; i++) {
        for(let j = 1; j <= s.length; j++) {
            if(t[i-1] === s[j-1]) {
                dp[i][j] = (dp[i-1][j-1] + dp[i-1][j]) % 1000000007;
            } else {
                dp[i][j] = dp[i-1][j];
            }
        }
    }

    return dp[t.length][s.length];
}
This JavaScript function utilizes a dynamic programming approach to solve the problem. First, it initializes a 2D array, `dp`, of size (t.length + 1) by (s.length + 1) with all elements set to 0. Then, it sets the base cases for `dp[i][0]`, where `i` is in the range of 0 to t.length and `dp[0][j]`, where `j` is in the range of 0 to s.length, to 1.

For each character in `s` and `t`, it checks if the current characters in `s` and `t` are equal. If they are, it adds the count of distinct subsequences in `s` without the current character in `t` and the count of distinct subsequences in `s` with the current character in `t` to the corresponding cell in `dp`. If the characters are not equal, it simply sets the count of distinct subsequences in `s` without the current character in `t` to the corresponding cell in `dp`.

Finally, it returns the count of distinct subsequences in `s` that equal `t` by going through the last cell of `dp`.

Note: The output will be a positive integer less than 1,000,000,007 (10^9 + 7).