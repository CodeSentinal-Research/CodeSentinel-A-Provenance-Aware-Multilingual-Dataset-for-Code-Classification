// P001410 - Count Bad Pairs
const fs = require("fs");

function main() {
    const input = fs.readFileSync(0, "utf8").trim().split(/\s+/);
    if (!input || input.length < 1) return;
    const n = parseInt(input[0], 10);
    const freq = new Map();
    let goodPairs = 0;
    for (let i = 0; i < n; i++) {
        const x = parseInt(input[1 + i], 10);
        const diff = x - i;
        const count = freq.get(diff) || 0;
        goodPairs += count;
        freq.set(diff, count + 1);
    }
    const totalPairs = (n * (n - 1)) / 2;
    console.log(totalPairs - goodPairs);
}

main();
