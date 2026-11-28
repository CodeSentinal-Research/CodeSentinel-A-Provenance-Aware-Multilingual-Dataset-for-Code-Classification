// P001268 - Maximum Number of Events That Can Be Attended
const fs = require("fs");

function main() {
    const input = fs.readFileSync(0, "utf8").trim().split(/\s+/);
    if (!input || input.length < 1) return;
    const n = parseInt(input[0], 10);
    let ptr = 1;
    const events = [];
    let maxDay = 0;
    for (let i = 0; i < n; i++) {
        const s = parseInt(input[ptr++], 10);
        const e = parseInt(input[ptr++], 10);
        events.push([s, e]);
        if (e > maxDay) maxDay = e;
    }
    events.sort((a, b) => a[0] - b[0]);
    let eIdx = 0, count = 0;
    const pq = [];
    for (let d = 1; d <= maxDay; d++) {
        while (eIdx < n && events[eIdx][0] === d) {
            pq.push(events[eIdx][1]);
            eIdx++;
        }
        pq.sort((a, b) => a - b);
        while (pq.length > 0 && pq[0] < d) pq.shift();
        if (pq.length > 0) {
            pq.shift();
            count++;
        }
        if (eIdx >= n && pq.length === 0) break;
    }
    console.log(count);
}

main();
