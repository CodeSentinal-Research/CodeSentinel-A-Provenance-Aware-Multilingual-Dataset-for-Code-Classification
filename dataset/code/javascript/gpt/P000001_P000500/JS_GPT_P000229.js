// P000229 - Find Row with Maximum 1s
const fs = require("fs");
const tokens = fs.readFileSync(0, "utf8").trim().split(/\s+/).map(Number);
let p = 0;
const r = tokens[p++], c = tokens[p++];
const a = Array.from({length: r}, () => tokens.slice(p, p += c));
let maxOnes = -1, bestRow = -1;
for (let i = 0; i < r; i++) {
    const count = a[i].filter(x => x === 1).length;
    if (count > maxOnes) { maxOnes = count; bestRow = i; }
}
console.log(bestRow);
