// P001202 - Largest Divisible Subset
const fs = require("fs");

function main() {
    const input = fs.readFileSync(0, "utf8").trim().split(/\s+/);
    if (!input || input.length < 2) return;
    const n = parseInt(input[0], 10);
    const days = [];
    for (let i = 0; i < n; i++) days.push(parseInt(input[1 + i], 10));
    let ptr = 1 + n;
    const costs = [
        parseInt(input[ptr++], 10),
        parseInt(input[ptr++], 10),
        parseInt(input[ptr++], 10)
    ];
    const lastDay = days[n - 1];
    const isTravel = new Array(lastDay + 1).fill(false);
    for (const d of days) isTravel[d] = true;
    const dp = new Array(lastDay + 1).fill(0);
    for (let i = 1; i <= lastDay; i++) {
        if (!isTravel[i]) {
            dp[i] = dp[i - 1];
        } else {
            dp[i] = Math.min(
                dp[i - 1] + costs[0],
                dp[Math.max(0, i - 7)] + costs[1],
                dp[Math.max(0, i - 30)] + costs[2]
            );
        }
    }
    console.log(dp[lastDay]);
}

main();
