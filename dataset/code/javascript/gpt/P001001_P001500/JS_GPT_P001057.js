// P001057 - Maximum Distinct Elements After K Removals
const fs = require("fs");

function main() {
    const input = fs.readFileSync(0, "utf8").trim().split(/\s+/);
    if (!input || input.length < 2) return;
    const n = parseInt(input[0], 10);
    let k = parseInt(input[1], 10);
    const freq = new Map();
    for (let i = 0; i < n; i++) {
        const val = parseInt(input[2 + i], 10);
        freq.set(val, (freq.get(val) || 0) + 1);
    }
    const counts = Array.from(freq.values()).sort((a, b) => a - b);
    let distinct = counts.length;
    for (let i = 0; i < counts.length; i++) {
        if (counts[i] > 1) {
            const extra = counts[i] - 1;
            if (k >= extra) {
                k -= extra;
            } else {
                k = 0;
                break;
            }
        }
    }
    if (k > 0) {
        distinct -= k;
    }
    console.log(Math.max(0, distinct));
}

main();
