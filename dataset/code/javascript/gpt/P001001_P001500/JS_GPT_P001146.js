// P001146 - Longest Common Subsequence
const fs = require("fs");

function main() {
    const lines = fs.readFileSync(0, "utf8").trim().split(/\r?\n/);
    if (!lines || lines.length < 2) return;
    const s1 = lines[0].trim();
    const s2 = lines[1].trim();
    const m = s1.length, n = s2.length;
    let dp = new Array(n + 1).fill(0);
    for (let i = 1; i <= m; i++) {
        const nextDp = new Array(n + 1).fill(0);
        for (let j = 1; j <= n; j++) {
            if (s1[i - 1] === s2[j - 1]) {
                nextDp[j] = dp[j - 1] + 1;
            } else {
                nextDp[j] = Math.max(dp[j], nextDp[j - 1]);
            }
        }
        dp = nextDp;
    }
    console.log(dp[n]);
}

main();
