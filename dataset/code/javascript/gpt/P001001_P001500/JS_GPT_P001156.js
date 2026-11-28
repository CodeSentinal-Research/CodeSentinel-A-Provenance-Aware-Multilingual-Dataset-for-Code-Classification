// P001156 - Egg Dropping Puzzle
const fs = require("fs");

function main() {
    const input = fs.readFileSync(0, "utf8").trim().split(/\s+/);
    if (!input || input.length < 2) return;
    const eggs = parseInt(input[0], 10);
    const floors = parseInt(input[1], 10);
    const dp = Array.from({ length: eggs + 1 }, () => new Array(floors + 1).fill(0));
    for (let i = 1; i <= eggs; i++) {
        dp[i][1] = 1;
        dp[i][0] = 0;
    }
    for (let j = 1; j <= floors; j++) dp[1][j] = j;
    for (let i = 2; i <= eggs; i++) {
        for (let j = 2; j <= floors; j++) {
            dp[i][j] = Infinity;
            for (let x = 1; x <= j; x++) {
                const res = 1 + Math.max(dp[i - 1][x - 1], dp[i][j - x]);
                if (res < dp[i][j]) dp[i][j] = res;
            }
        }
    }
    console.log(dp[eggs][floors]);
}

main();
