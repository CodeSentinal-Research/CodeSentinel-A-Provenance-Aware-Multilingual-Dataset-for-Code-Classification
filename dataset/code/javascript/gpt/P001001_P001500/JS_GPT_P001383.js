// P001383 - Intersection of Two Arrays II
const fs = require("fs");

function main() {
    const input = fs.readFileSync(0, "utf8").trim().split(/\s+/);
    if (!input || input.length < 2) return;
    const n = parseInt(input[0], 10);
    const m = parseInt(input[1], 10);
    let ptr = 2;
    const count = new Map();
    for (let i = 0; i < n; i++) {
        const x = parseInt(input[ptr++], 10);
        count.set(x, (count.get(x) || 0) + 1);
    }
    const res = [];
    for (let i = 0; i < m; i++) {
        const x = parseInt(input[ptr++], 10);
        if (count.has(x) && count.get(x) > 0) {
            res.push(x);
            count.set(x, count.get(x) - 1);
        }
    }
    res.sort((a, b) => a - b);
    console.log(res.join(" "));
}

main();
