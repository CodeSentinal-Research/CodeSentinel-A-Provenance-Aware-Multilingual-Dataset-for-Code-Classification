// P001462 - Remove Duplicates from Sorted Array
const fs = require("fs");

function main() {
    const input = fs.readFileSync(0, "utf8").trim().split(/\s+/);
    if (!input || input.length < 2) return;
    const n = parseInt(input[0], 10);
    const k = parseInt(input[1], 10);
    const freq = new Map();
    freq.set(0, 1);
    let sum = 0, ans = 0;
    for (let i = 0; i < n; i++) {
        const x = parseInt(input[2 + i], 10);
        sum += x;
        const rem = ((sum % k) + k) % k;
        const count = freq.get(rem) || 0;
        ans += count;
        freq.set(rem, count + 1);
    }
    console.log(ans);
}

main();
