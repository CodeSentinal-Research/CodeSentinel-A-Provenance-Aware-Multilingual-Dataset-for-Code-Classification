// P001467 - Reverse Vowels of a String
const fs = require("fs");

function main() {
    const input = fs.readFileSync(0, "utf8").trim().split(/\s+/);
    if (!input || input.length < 2) return;
    const n = parseInt(input[0], 10);
    const k = parseInt(input[1], 10);
    const nums = [];
    for (let i = 0; i < n; i++) nums.push(parseInt(input[2 + i], 10));
    const count = new Map();
    for (const x of nums) count.set(x, (count.get(x) || 0) + 1);
    let duplicates = 0;
    for (const c of count.values()) {
        duplicates += c - 1;
    }
    if (duplicates >= k) {
        console.log(count.size);
    } else {
        const remaining = k - duplicates;
        console.log(count.size - remaining);
    }
}

main();
