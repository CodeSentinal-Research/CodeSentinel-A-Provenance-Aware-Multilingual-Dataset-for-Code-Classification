// P001384 - Find All Duplicates in an Array
const fs = require("fs");

function main() {
    const input = fs.readFileSync(0, "utf8").trim().split(/\s+/);
    if (!input || input.length < 1) return;
    const n = parseInt(input[0], 10);
    const seen = new Set();
    const dups = new Set();
    for (let i = 0; i < n; i++) {
        const x = parseInt(input[1 + i], 10);
        if (seen.has(x)) dups.add(x);
        else seen.add(x);
    }
    const sorted = Array.from(dups).sort((a, b) => a - b);
    console.log(sorted.join(" "));
}

main();
