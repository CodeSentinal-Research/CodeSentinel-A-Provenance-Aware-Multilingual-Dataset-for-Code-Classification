// P000155 - Maximum Consecutive Ones
const fs = require("fs");
const tokens = fs.readFileSync(0, "utf8").trim().split(/\s+/).map(Number);
let p = 0;
const n = tokens[p++];
const a = tokens.slice(p, p + n);
let maxCount = 0, current = 0;
for (const x of a) {
    if (x === 1) { current++; maxCount = Math.max(maxCount, current); }
    else current = 0;
}
console.log(maxCount);
