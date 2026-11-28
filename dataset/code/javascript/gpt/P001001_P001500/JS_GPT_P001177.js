// P001177 - Minimum Cost to Reach Last Cell
const fs = require("fs");

function main() {
    const input = fs.readFileSync(0, "utf8").trim().split(/\s+/);
    if (!input || input.length < 2) return;
    const r = parseInt(input[0], 10);
    const c = parseInt(input[1], 10);
    let ptr = 2;
    const cost = [];
    for (let i = 0; i < r; i++) {
        const row = [];
        for (let j = 0; j < c; j++) row.push(parseInt(input[ptr++], 10));
        cost.push(row);
    }
    for (let i = 1; i < r; i++) cost[i][0] += cost[i - 1][0];
    for (let j = 1; j < c; j++) cost[0][j] += cost[0][j - 1];
    for (let i = 1; i < r; i++) {
        for (let j = 1; j < c; j++) {
            cost[i][j] += Math.min(cost[i - 1][j], cost[i][j - 1], cost[i - 1][j - 1]);
        }
    }
    console.log(cost[r - 1][c - 1]);
}

main();
