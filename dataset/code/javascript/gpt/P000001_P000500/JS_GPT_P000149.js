// P000149 - Row with Maximum Number of 1s
const fs = require("fs");
const tokens = fs.readFileSync(0, "utf8").trim().split(/\s+/).map(Number);
let p = 0;
const rows = tokens[p++], cols = tokens[p++];
const mat = Array.from({length: rows}, () => tokens.slice(p, p += cols));
let maxIdx = 0, maxCount = -1;
for (let i = 0; i < rows; i++) {
    const ones = mat[i].filter(x => x === 1).length;
    if (ones > maxCount) { maxCount = ones; maxIdx = i; }
}
console.log(maxIdx);
