// P001160 - Distinct Subsequences
const fs = require("fs");

function main() {
    const lines = fs.readFileSync(0, "utf8").trim().split(/\r?\n/);
    if (!lines || lines.length < 2) return;
    const s = lines[0].trim();
    const t = lines[1].trim();
    const m = s.length, n = t.length;
    const dp = Array.from({ length: m + 1 }, () => new Array(n + 1).fill(0n));
    for (let i = 0; i <= m; i++) dp[i][0] = 1n;
    for (let i = 1; i <= m; i++) {
        for (let j = 1; j <= n; j++) {
            if (s[i - 1] === t[j - 1]) {
                dp[i][j] = dp[i - 1][j - 1] + dp[i - 1][j];
            } else {
                dp[i][j] = dp[i - 1][j];
            }
        }
    }
    console.log(dp[m][n].toString());
}

main();
