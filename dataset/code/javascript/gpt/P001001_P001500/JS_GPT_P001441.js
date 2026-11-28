// P001441 - Count Number of Pairs With Absolute Difference K
const fs = require("fs");

function main() {
    const input = fs.readFileSync(0, "utf8").trim().split(/\s+/);
    if (!input || input.length < 2) return;
    const n = parseInt(input[0], 10);
    const k = parseInt(input[1], 10);
    const count = new Map();
    let pairs = 0;
    for (let i = 0; i < n; i++) {
        const x = parseInt(input[2 + i], 10);
        pairs += (count.get(x - k) || 0) + (count.get(x + k) || 0);
        count.set(x, (count.get(x) || 0) + 1);
    }
    console.log(pairs);
}

main();
