// P001138 - Coin Change - Number of Ways
const fs = require("fs");

function main() {
    const input = fs.readFileSync(0, "utf8").trim().split(/\s+/);
    if (!input || input.length < 2) return;
    const n = parseInt(input[0], 10);
    const amount = parseInt(input[1], 10);
    const coins = [];
    for (let i = 0; i < n; i++) coins.push(parseInt(input[2 + i], 10));
    const dp = new Array(amount + 1).fill(0n);
    dp[0] = 1n;
    for (const c of coins) {
        for (let j = c; j <= amount; j++) {
            dp[j] += dp[j - c];
        }
    }
    console.log(dp[amount].toString());
}

main();
