// P001241 - Gas Station Circuit
const fs = require("fs");

function main() {
    const input = fs.readFileSync(0, "utf8").trim().split(/\s+/);
    if (!input || input.length < 1) return;
    const n = parseInt(input[0], 10);
    let ptr = 1;
    const intervals = [];
    for (let i = 0; i < n; i++) {
        const s = parseInt(input[ptr++], 10);
        const e = parseInt(input[ptr++], 10);
        intervals.push([s, e]);
    }
    intervals.sort((a, b) => a[1] - b[1]);
    let removed = 0, lastEnd = -Infinity;
    for (const [s, e] of intervals) {
        if (s >= lastEnd) {
            lastEnd = e;
        } else {
            removed++;
        }
    }
    console.log(removed);
}

main();
