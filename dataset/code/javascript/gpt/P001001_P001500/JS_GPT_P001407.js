// P001407 - Find Original Array From Doubled Array
const fs = require("fs");

function main() {
    const input = fs.readFileSync(0, "utf8").trim().split(/\s+/);
    if (!input || input.length < 1) return;
    const n = parseInt(input[0], 10);
    if (n % 2 !== 0) {
        console.log("-1");
        return;
    }
    const changed = [];
    for (let i = 0; i < n; i++) changed.push(parseInt(input[1 + i], 10));
    changed.sort((a, b) => a - b);
    const freq = new Map();
    for (const x of changed) freq.set(x, (freq.get(x) || 0) + 1);
    const original = [];
    for (const x of changed) {
        if ((freq.get(x) || 0) === 0) continue;
        freq.set(x, freq.get(x) - 1);
        const doubleVal = 2 * x;
        if ((freq.get(doubleVal) || 0) === 0) {
            console.log("-1");
            return;
        }
        freq.set(doubleVal, freq.get(doubleVal) - 1);
        original.push(x);
    }
    console.log(original.join(" "));
}

main();
