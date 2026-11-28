// P001054 - K Largest Pair Sums
const fs = require("fs");

function main() {
    const input = fs.readFileSync(0, "utf8").trim().split(/\s+/);
    if (!input || input.length < 3) return;
    const n = parseInt(input[0], 10);
    const m = parseInt(input[1], 10);
    const k = parseInt(input[2], 10);
    let ptr = 3;
    const a = [];
    for (let i = 0; i < n; i++) a.push(parseInt(input[ptr++], 10));
    const b = [];
    for (let i = 0; i < m; i++) b.push(parseInt(input[ptr++], 10));
    a.sort((x, y) => y - x);
    b.sort((x, y) => y - x);
    const sums = [];
    for (let i = 0; i < Math.min(n, k); i++) {
        for (let j = 0; j < Math.min(m, k); j++) {
            sums.push(a[i] + b[j]);
        }
    }
    sums.sort((x, y) => y - x);
    console.log(sums.slice(0, k).join(" "));
}

main();
