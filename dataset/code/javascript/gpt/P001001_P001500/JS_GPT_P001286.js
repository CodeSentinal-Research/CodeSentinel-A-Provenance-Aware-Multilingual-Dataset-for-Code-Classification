// P001286 - Bag Filling with Additional Rocks
const fs = require("fs");

function main() {
    const input = fs.readFileSync(0, "utf8").trim().split(/\s+/);
    if (!input || input.length < 2) return;
    const n = parseInt(input[0], 10);
    let addRocks = parseInt(input[1], 10);
    let ptr = 2;
    const cap = [];
    for (let i = 0; i < n; i++) cap.push(parseInt(input[ptr++], 10));
    const rocks = [];
    for (let i = 0; i < n; i++) rocks.push(parseInt(input[ptr++], 10));
    const diff = [];
    for (let i = 0; i < n; i++) diff.push(cap[i] - rocks[i]);
    diff.sort((a, b) => a - b);
    let full = 0;
    for (const d of diff) {
        if (addRocks >= d) {
            addRocks -= d;
            full++;
        } else {
            break;
        }
    }
    console.log(full);
}

main();
