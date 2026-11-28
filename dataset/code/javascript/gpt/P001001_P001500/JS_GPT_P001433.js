// P001433 - Count Good Pairs
const fs = require("fs");

function main() {
    const input = fs.readFileSync(0, "utf8").trim().split(/\s+/);
    if (!input || input.length < 1) return;
    const n = parseInt(input[0], 10);
    const map = new Map();
    let pairs = 0;
    for (let i = 0; i < n; i++) {
        const x = parseInt(input[1 + i], 10);
        const count = map.get(x) || 0;
        pairs += count;
        map.set(x, count + 1);
    }
    console.log(pairs);
}

main();
