// P001245 - Queue Reconstruction by Height
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
    for (let i = 1; i < n; i++) {
        if (intervals[i][0] < intervals[i - 1][1]) {
            console.log("NO");
            return;
        }
    }
    console.log("YES");
}

main();
