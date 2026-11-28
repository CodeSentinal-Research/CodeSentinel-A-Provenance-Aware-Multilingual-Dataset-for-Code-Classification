// P001150 - Longest Palindromic Subsequence
const fs = require("fs");

function main() {
    const s = fs.readFileSync(0, "utf8").trim();
    if (!s) return;
    const n = s.length;
    let dp = new Array(n).fill(0);
    for (let i = n - 1; i >= 0; i--) {
        const nextDp = new Array(n).fill(0);
        nextDp[i] = 1;
        for (let j = i + 1; j < n; j++) {
            if (s[i] === s[j]) {
                nextDp[j] = dp[j - 1] + 2;
            } else {
                nextDp[j] = Math.max(dp[j], nextDp[j - 1]);
            }
        }
        dp = nextDp;
    }
    console.log(dp[n - 1]);
}

main();
