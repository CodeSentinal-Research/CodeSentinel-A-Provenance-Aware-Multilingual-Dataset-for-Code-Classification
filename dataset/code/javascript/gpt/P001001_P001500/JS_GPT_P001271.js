// P001271 - Minimum Number of Taps to Water a Garden
const fs = require("fs");

function main() {
    const input = fs.readFileSync(0, "utf8").trim().split(/\s+/);
    if (!input || input.length < 1) return;
    const n = parseInt(input[0], 10);
    const ranges = [];
    for (let i = 0; i <= n; i++) ranges.push(parseInt(input[1 + i], 10));
    const maxReach = new Array(n + 1).fill(0);
    for (let i = 0; i <= n; i++) {
        const l = Math.max(0, i - ranges[i]);
        const r = Math.min(n, i + ranges[i]);
        maxReach[l] = Math.max(maxReach[l], r);
    }
    let taps = 0, curEnd = 0, farthest = 0;
    for (let i = 0; i < n; i++) {
        farthest = Math.max(farthest, maxReach[i]);
        if (i === curEnd) {
            taps++;
            curEnd = farthest;
            if (curEnd <= i) {
                console.log(-1);
                return;
            }
        }
    }
    console.log(taps);
}

main();
