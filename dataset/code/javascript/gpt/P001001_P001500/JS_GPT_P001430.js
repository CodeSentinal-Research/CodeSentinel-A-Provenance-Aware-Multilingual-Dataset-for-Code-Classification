// P001430 - Find the Prefix Common Array of Two Arrays
const fs = require("fs");

function main() {
    const input = fs.readFileSync(0, "utf8").trim().split(/\s+/);
    if (!input || input.length < 2) return;
    const n = parseInt(input[0], 10);
    let original = parseInt(input[1], 10);
    const set = new Set();
    for (let i = 0; i < n; i++) set.add(parseInt(input[2 + i], 10));
    while (set.has(original)) {
        original *= 2;
    }
    console.log(original);
}

main();
