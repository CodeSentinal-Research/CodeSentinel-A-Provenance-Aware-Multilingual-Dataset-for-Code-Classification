// P001274 - Maximum Ice Cream Bars
const fs = require("fs");

function main() {
    const input = fs.readFileSync(0, "utf8").trim().split(/\s+/);
    if (!input || input.length < 2) return;
    const n = parseInt(input[0], 10);
    let coins = parseInt(input[1], 10);
    const costs = [];
    for (let i = 0; i < n; i++) costs.push(parseInt(input[2 + i], 10));
    costs.sort((a, b) => a - b);
    let count = 0;
    for (const c of costs) {
        if (coins >= c) {
            coins -= c;
            count++;
        } else {
            break;
        }
    }
    console.log(count);
}

main();
