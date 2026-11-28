// P001210 - Optimal Strategy for a Game
const fs = require("fs");

function main() {
    const input = fs.readFileSync(0, "utf8").trim();
    if (!input) return;
    const n = parseInt(input, 10);
    if (n === 0) { console.log(0); return; }
    if (n === 1) { console.log(1); return; }
    if (n === 2) { console.log(2); return; }
    if (n === 3) { console.log(5); return; }
    const MOD = 1000000007n;
    const dp = new Array(n + 1).fill(0n);
    dp[0] = 1n; dp[1] = 1n; dp[2] = 2n; dp[3] = 5n;
    for (let i = 4; i <= n; i++) {
        dp[i] = (2n * dp[i - 1] + dp[i - 3]) % MOD;
    }
    console.log(dp[n].toString());
}

main();
