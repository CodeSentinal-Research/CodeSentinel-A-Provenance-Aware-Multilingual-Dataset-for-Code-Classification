// P001035 - Kth Smallest Element in a Sorted Matrix
const fs = require("fs");

function main() {
    const input = fs.readFileSync(0, "utf8").trim().split(/\s+/);
    if (!input || input.length < 2) return;
    const n = parseInt(input[0], 10);
    const k = parseInt(input[1], 10);
    const all = [];
    let ptr = 2;
    for (let i = 0; i < n * n; i++) all.push(parseInt(input[ptr++], 10));
    all.sort((a, b) => a - b);
    console.log(all[k - 1]);
}

main();
