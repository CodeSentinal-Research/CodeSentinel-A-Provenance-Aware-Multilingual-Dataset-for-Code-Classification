// P001302 - Minimum Number of Meeting Rooms
const fs = require("fs");

function main() {
    const input = fs.readFileSync(0, "utf8").trim().split(/\s+/);
    if (!input || input.length < 1) return;
    const n = parseInt(input[0], 10);
    let ptr = 1;
    const starts = [], ends = [];
    for (let i = 0; i < n; i++) {
        starts.push(parseInt(input[ptr++], 10));
        ends.push(parseInt(input[ptr++], 10));
    }
    starts.sort((a, b) => a - b);
    ends.sort((a, b) => a - b);
    let rooms = 0, endIdx = 0;
    for (let i = 0; i < n; i++) {
        if (starts[i] < ends[endIdx]) {
            rooms++;
        } else {
            endIdx++;
        }
    }
    console.log(rooms);
}

main();
