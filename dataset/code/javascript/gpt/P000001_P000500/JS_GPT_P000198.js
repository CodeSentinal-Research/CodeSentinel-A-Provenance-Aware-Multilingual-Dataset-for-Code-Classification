// P000198 - Check if Array Contains Contiguous Integers
const fs = require("fs");
const tokens = fs.readFileSync(0, "utf8").trim().split(/\s+/).map(Number);
let p = 0;
const n = tokens[p++];
const a = tokens.slice(p, p + n);
const sorted = Array.from(new Set(a)).sort((x, y) => x - y);
let contiguous = true;
for (let i = 1; i < sorted.length; i++) {
    if (sorted[i] !== sorted[i - 1] + 1) { contiguous = false; break; }
}
console.log(contiguous ? "Yes" : "No");
