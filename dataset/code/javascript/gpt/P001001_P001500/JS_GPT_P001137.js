// P001137 - Coin Change - Minimum Coins
const fs = require("fs");

function main() {
    const input = fs.readFileSync(0, "utf8").trim().split(/\s+/);
    if (!input || input.length < 2) return;
    const n = parseInt(input[0], 10);
    const amount = parseInt(input[1], 10);
    const coins = [];
    for (let i = 0; i < n; i++) coins.push(parseInt(input[2 + i], 10));
    const dp = new Array(amount + 1).fill(Infinity);
    dp[0] = 0;
    for (const c of coins) {
        for (let j = c; j <= amount; j++) {
            if (dp[j - c] !== Infinity) {
                dp[j] = Math.min(dp[j], dp[j - c] + 1);
            }
        }
    }
    console.log(dp[amount] === Infinity ? -1 : dp[amount]);
}

main();
