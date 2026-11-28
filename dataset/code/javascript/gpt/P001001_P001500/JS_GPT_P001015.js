// P001015 - Top K Frequent Elements
const fs = require("fs");

function main() {
    const input = fs.readFileSync(0, "utf8").trim().split(/\s+/);
    if (!input || input.length < 2) return;
    const n = parseInt(input[0], 10);
    const k = parseInt(input[1], 10);
    const freq = new Map();
    for (let i = 0; i < n; i++) {
        const val = parseInt(input[2 + i], 10);
        freq.set(val, (freq.get(val) || 0) + 1);
    }
    const sorted = Array.from(freq.entries()).sort((a, b) => {
        if (b[1] !== a[1]) return b[1] - a[1];
        return a[0] - b[0];
    });
    const result = sorted.slice(0, k).map(e => e[0]);
    console.log(result.join(" "));
}

main();
