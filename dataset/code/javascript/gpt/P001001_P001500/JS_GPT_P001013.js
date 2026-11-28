// P001013 - Running Median of a Data Stream
const fs = require("fs");

function main() {
    const input = fs.readFileSync(0, "utf8").trim().split(/\s+/);
    if (!input || input.length < 1) return;
    const n = parseInt(input[0], 10);
    const sorted = [];
    const res = [];
    for (let i = 0; i < n; i++) {
        const val = parseFloat(input[1 + i]);
        let low = 0, high = sorted.length;
        while (low < high) {
            const mid = (low + high) >> 1;
            if (sorted[mid] < val) low = mid + 1;
            else high = mid;
        }
        sorted.splice(low, 0, val);
        const len = sorted.length;
        if (len % 2 === 1) {
            res.push(sorted[Math.floor(len / 2)].toFixed(1));
        } else {
            const mid1 = sorted[len / 2 - 1];
            const mid2 = sorted[len / 2];
            res.push(((mid1 + mid2) / 2).toFixed(1));
        }
    }
    for (const line of res) {
        console.log(line);
    }
}

main();
