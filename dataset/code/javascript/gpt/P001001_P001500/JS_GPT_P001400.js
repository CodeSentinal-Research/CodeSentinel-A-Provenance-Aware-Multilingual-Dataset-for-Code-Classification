// P001400 - Find the Difference of Two Arrays
const fs = require("fs");

function main() {
    const input = fs.readFileSync(0, "utf8").trim().split(/\s+/);
    if (!input || input.length < 2) return;
    const n = parseInt(input[0], 10);
    const m = parseInt(input[1], 10);
    let ptr = 2;
    const s1 = new Set();
    for (let i = 0; i < n; i++) s1.add(parseInt(input[ptr++], 10));
    const s2 = new Set();
    for (let i = 0; i < m; i++) s2.add(parseInt(input[ptr++], 10));
    const d1 = [], d2 = [];
    for (const x of s1) if (!s2.has(x)) d1.push(x);
    for (const x of s2) if (!s1.has(x)) d2.push(x);
    d1.sort((a, b) => a - b);
    d2.sort((a, b) => a - b);
    console.log(d1.join(" "));
    console.log(d2.join(" "));
}

main();
