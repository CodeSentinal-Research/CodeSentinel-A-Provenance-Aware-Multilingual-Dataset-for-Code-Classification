// P001243 - Lemonade Change
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
    intervals.sort((a, b) => a[0] - b[0]);
    const merged = [intervals[0]];
    for (let i = 1; i < n; i++) {
        const last = merged[merged.length - 1];
        if (intervals[i][0] <= last[1]) {
            last[1] = Math.max(last[1], intervals[i][1]);
        } else {
            merged.push(intervals[i]);
        }
    }
    for (const [s, e] of merged) {
        console.log(s + " " + e);
    }
}

main();
