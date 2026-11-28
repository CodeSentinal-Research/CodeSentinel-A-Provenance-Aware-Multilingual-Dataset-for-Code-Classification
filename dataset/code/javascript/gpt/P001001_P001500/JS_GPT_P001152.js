// P001152 - Count Palindromic Subsequences
const fs = require("fs");

function main() {
    const s = fs.readFileSync(0, "utf8").trim();
    if (!s) return;
    const n = s.length;
    const MOD = 1000000007n;
    const dp = Array.from({ length: n }, () => new Array(n).fill(0n));
    for (let i = 0; i < n; i++) dp[i][i] = 1n;
    for (let len = 2; len <= n; len++) {
        for (let i = 0; i <= n - len; i++) {
            const j = i + len - 1;
            if (s[i] === s[j]) {
                dp[i][j] = (dp[i + 1][j] + dp[i][j - 1] + 1n) % MOD;
            } else {
                dp[i][j] = (dp[i + 1][j] + dp[i][j - 1] - dp[i + 1][j - 1] + MOD) % MOD;
            }
        }
    }
    console.log(dp[0][n - 1].toString());
}

main();
