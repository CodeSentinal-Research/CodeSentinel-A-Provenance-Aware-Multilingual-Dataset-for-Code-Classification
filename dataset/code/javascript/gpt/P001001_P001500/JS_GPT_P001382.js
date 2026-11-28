// P001382 - Intersection of Two Arrays
const fs = require("fs");

function main() {
    const input = fs.readFileSync(0, "utf8").trim().split(/\s+/);
    if (!input || input.length < 2) return;
    const n = parseInt(input[0], 10);
    const m = parseInt(input[1], 10);
    let ptr = 2;
    const set1 = new Set();
    for (let i = 0; i < n; i++) set1.add(parseInt(input[ptr++], 10));
    const res = new Set();
    for (let i = 0; i < m; i++) {
        const x = parseInt(input[ptr++], 10);
        if (set1.has(x)) res.add(x);
    }
    const sorted = Array.from(res).sort((a, b) => a - b);
    console.log(sorted.join(" "));
}

main();
