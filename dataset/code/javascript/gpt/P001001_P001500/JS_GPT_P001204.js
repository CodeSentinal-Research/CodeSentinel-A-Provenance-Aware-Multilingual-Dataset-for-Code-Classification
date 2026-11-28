// P001204 - Wiggle Subsequence
const fs = require("fs");

function main() {
    const input = fs.readFileSync(0, "utf8").trim().split(/\s+/);
    if (!input || input.length < 3) return;
    const n = parseInt(input[0], 10);
    const k = parseInt(input[1], 10);
    const target = parseInt(input[2], 10);
    const MOD = 1000000007n;
    let dp = new Array(target + 1).fill(0n);
    dp[0] = 1n;
    for (let d = 1; d <= n; d++) {
        const nextDp = new Array(target + 1).fill(0n);
        for (let s = 1; s <= target; s++) {
            for (let face = 1; face <= k; face++) {
                if (s >= face) {
                    nextDp[s] = (nextDp[s] + dp[s - face]) % MOD;
                }
            }
        }
        dp = nextDp;
    }
    console.log(dp[target].toString());
}

main();
