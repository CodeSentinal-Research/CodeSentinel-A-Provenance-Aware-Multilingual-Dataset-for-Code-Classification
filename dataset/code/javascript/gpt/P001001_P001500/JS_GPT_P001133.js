// P001133 - Min Cost Climbing Stairs
const fs = require("fs");

function main() {
    const input = fs.readFileSync(0, "utf8").trim().split(/\s+/);
    if (!input || input.length < 1) return;
    const n = parseInt(input[0], 10);
    const cost = [];
    for (let i = 0; i < n; i++) cost.push(parseInt(input[1 + i], 10));
    let first = cost[0], second = cost[1];
    for (let i = 2; i < n; i++) {
        const curr = cost[i] + Math.min(first, second);
        first = second;
        second = curr;
    }
    console.log(Math.min(first, second));
}

main();
