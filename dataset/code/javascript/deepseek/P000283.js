Here's the JavaScript code for finding the length of the longest common subsequence (LCS) of two strings.

function longestCommonSubsequence(s1, s2) {
  const m = s1.length;
  const n = s2.length;
  const dp = Array.from(new Array(m + 1), () => new Array(n + 1).fill(0));

  for (let i = 1; i <= m; i++) {
    for (let j = 1; j <= n; j++) {
      if (s1[i - 1] === s2[j - 1]) {
        dp[i][j] = dp[i - 1][j - 1] + 1;
      } else {
        dp[i][j] = Math.max(dp[i - 1][j], dp[i][j - 1]);
      }
    }
  }

  return dp[m][n];
}

console.log(longestCommonSubsequence('ABCBDAB', 'BDCAB')); // Output: 4
console.log(longestCommonSubsequence('ABCDEF', 'ACDFE')); // Output: 5

This function uses a 2D dynamic programming table `dp` where `dp[i][j]` represents the length of the longest common subsequence of the first `i` characters of `s1` and the first `j` characters of `s2`.

The base cases for the dynamic programming table are `dp[0][j] = 0` and `dp[i][0] = 0` for `i` in `0...m`, where `m` is the length of `s1`.

The dynamic programming formula for `dp[i][j]` is derived from the following:
- If `s1[i - 1]` and `s2[j - 1]` are equal, then the length of the longest common subsequence of the first `i - 1` characters of `s1` and the first `j - 1` characters of `s2` is `dp[i - 1][j - 1] + 1`.
- If `s1[i - 1]` and `s2[j - 1]` are not equal, then the length of the longest common subsequence of the first `i - 1` characters of `s1` and the first `j` characters of `s2` is `max(dp[i - 1][j], dp[i][j - 1])`.

The time complexity of this function is O(m * n), where m and n are the lengths of the two input strings.