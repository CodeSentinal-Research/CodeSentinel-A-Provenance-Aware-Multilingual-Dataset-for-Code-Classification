// P001221 - Generate All Unique Binary Search Trees
const fs = require("fs");

function main() {
    const input = fs.readFileSync(0, "utf8").trim().split(/\s+/);
    if (!input || input.length < 2) return;
    const steps = parseInt(input[0], 10);
    const arrLen = parseInt(input[1], 10);
    const maxPos = Math.min(Math.floor(steps / 2), arrLen - 1);
    const MOD = 1000000007n;
    let dp = new Array(maxPos + 1).fill(0n);
    dp[0] = 1n;
    for (let step = 1; step <= steps; step++) {
        const nextDp = new Array(maxPos + 1).fill(0n);
        for (let j = 0; j <= maxPos; j++) {
            nextDp[j] = dp[j];
            if (j > 0) nextDp[j] = (nextDp[j] + dp[j - 1]) % MOD;
            if (j < maxPos) nextDp[j] = (nextDp[j] + dp[j + 1]) % MOD;
        }
        dp = nextDp;
    }
    console.log(dp[0].toString());
}

main();
