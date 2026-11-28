// P001460 - Count Equal XOR Prefix Pairs
const fs = require("fs");

function main() {
    const input = fs.readFileSync(0, "utf8").trim().split(/\s+/);
    if (!input || input.length < 1) return;
    const n = parseInt(input[0], 10);
    const freq = new Map();
    freq.set(0, 1);
    let curXor = 0, pairs = 0;
    for (let i = 0; i < n; i++) {
        const val = parseInt(input[1 + i], 10);
        curXor ^= val;
        const count = freq.get(curXor) || 0;
        pairs += count;
        freq.set(curXor, count + 1);
    }
    console.log(pairs);
}

main();
