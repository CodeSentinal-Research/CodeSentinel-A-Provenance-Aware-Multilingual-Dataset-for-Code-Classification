// P001225 - Domino and Tromino Tiling
const fs = require("fs");

function main() {
    const input = fs.readFileSync(0, "utf8").trim().split(/\s+/);
    if (!input || input.length < 10) return;
    const cost = [];
    for (let i = 0; i < 9; i++) cost.push(parseInt(input[i], 10));
    const target = parseInt(input[9], 10);
    const dp = new Array(target + 1).fill(-Infinity);
    dp[0] = 0;
    for (let i = 1; i <= target; i++) {
        for (let d = 0; d < 9; d++) {
            if (i >= cost[d]) {
                dp[i] = Math.max(dp[i], dp[i - cost[d]] + 1);
            }
        }
    }
    if (dp[target] < 0) {
        console.log("0");
        return;
    }
    let res = "";
    let rem = target;
    for (let d = 8; d >= 0; d--) {
        while (rem >= cost[d] && dp[rem] === dp[rem - cost[d]] + 1) {
            res += (d + 1).toString();
            rem -= cost[d];
        }
    }
    console.log(res);
}

main();
