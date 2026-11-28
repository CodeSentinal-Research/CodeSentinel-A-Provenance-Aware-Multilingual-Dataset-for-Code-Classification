// P000174 - Find Minimum Difference
const fs = require("fs");
const tokens = fs.readFileSync(0, "utf8").trim().split(/\s+/).map(Number);
let p = 0;
const n = tokens[p++];
const a = tokens.slice(p, p + n).sort((x, y) => x - y);
let minDiff = Infinity;
for (let i = 0; i < n - 1; i++) {
    minDiff = Math.min(minDiff, a[i + 1] - a[i]);
}
console.log(minDiff);
