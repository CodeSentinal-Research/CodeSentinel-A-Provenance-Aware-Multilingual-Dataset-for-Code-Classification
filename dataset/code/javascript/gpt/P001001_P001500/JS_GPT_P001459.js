// P001459 - Smallest Missing Positive Using Hashing
const fs = require("fs");

function main() {
    const input = fs.readFileSync(0, "utf8").trim().split(/\s+/);
    if (!input || input.length < 1) return;
    const n = parseInt(input[0], 10);
    const set = new Set();
    for (let i = 0; i < n; i++) {
        set.add(parseInt(input[1 + i], 10));
    }
    let missing = 1;
    while (set.has(missing)) {
        missing++;
    }
    console.log(missing);
}

main();
