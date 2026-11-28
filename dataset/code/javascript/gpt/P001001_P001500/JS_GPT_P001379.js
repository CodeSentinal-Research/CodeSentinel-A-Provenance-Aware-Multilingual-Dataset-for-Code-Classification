// P001379 - Top K Frequent Elements
const fs = require("fs");

function main() {
    const input = fs.readFileSync(0, "utf8").trim().split(/\s+/);
    if (!input || input.length < 2) return;
    const n = parseInt(input[0], 10);
    const k = parseInt(input[1], 10);
    const count = new Map();
    for (let i = 0; i < n; i++) {
        const val = parseInt(input[2 + i], 10);
        count.set(val, (count.get(val) || 0) + 1);
    }
    const sorted = Array.from(count.entries()).sort((a, b) => b[1] - a[1]);
    const res = sorted.slice(0, k).map(e => e[0]);
    console.log(res.join(" "));
}

main();
