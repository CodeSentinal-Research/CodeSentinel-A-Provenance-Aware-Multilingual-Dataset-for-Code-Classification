Here is the JavaScript code for the problem:

const readline = require('readline');

const rl = readline.createInterface({
    input: process.stdin,
    output: process.stdout
});

let [S, T] = rl.question('').split('\n');

S = S.trim();
T = T.trim();

function numDistinct(s, t) {
    let m = s.length;
    let n = t.length;
    let dp = new Array(m + 1);
    for (let i = 0; i <= m; i++) {
        dp[i] = new Array(n + 1).fill(0);
    }
    dp[0][0] = 1;
    for (let i = 1; i <= m; i++) {
        for (let j = 1; j <= n; j++) {
            if (s[i - 1] == t[j - 1]) {
                dp[i][j] = dp[i - 1][j - 1] + dp[i - 1][j];
            } else {
                dp[i][j] = dp[i - 1][j];
            }
        }
    }
    return dp[m][n];
}

console.log(numDistinct(S, T));
rl.close();
This code first reads two strings from the standard input, then it calculates the number of distinct subsequences of the first string that equals the second string. The DP solution is used to solve this problem. The DP table dp[i][j] represents the number of distinct subsequences of the first i characters of S and the first j characters of T. If s[i-1] equals t[j-1], then dp[i][j] = dp[i-1][j-1] + dp[i-1][j] because we can append s[i-1] to the subsequence and also append dp[i-1][j] (which is the number of distinct subsequences of the first i-1 characters of S and the first j characters of T) to it. Otherwise, dp[i][j] = dp[i-1][j] because we can not append s[i-1] to the subsequence.