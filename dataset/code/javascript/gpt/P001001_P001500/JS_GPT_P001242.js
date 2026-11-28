// P001242 - Candy Distribution
const fs = require("fs");

function main() {
    const input = fs.readFileSync(0, "utf8").trim().split(/\s+/);
    if (!input || input.length < 3) return;
    const n = parseInt(input[0], 10);
    let newStart = parseInt(input[1], 10);
    let newEnd = parseInt(input[2], 10);
    let ptr = 3;
    const intervals = [];
    for (let i = 0; i < n; i++) {
        const s = parseInt(input[ptr++], 10);
        const e = parseInt(input[ptr++], 10);
        intervals.push([s, e]);
    }
    const res = [];
    let i = 0;
    while (i < n && intervals[i][1] < newStart) {
        res.push(intervals[i++]);
    }
    while (i < n && intervals[i][0] <= newEnd) {
        newStart = Math.min(newStart, intervals[i][0]);
        newEnd = Math.max(newEnd, intervals[i][1]);
        i++;
    }
    res.push([newStart, newEnd]);
    while (i < n) {
        res.push(intervals[i++]);
    }
    for (const [s, e] of res) {
        console.log(s + " " + e);
    }
}

main();
