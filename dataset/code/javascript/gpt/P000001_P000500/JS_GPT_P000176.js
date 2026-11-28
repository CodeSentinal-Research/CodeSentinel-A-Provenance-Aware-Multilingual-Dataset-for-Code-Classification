// P000176 - Chocolate Distribution Problem
const fs = require("fs");
const tokens = fs.readFileSync(0, "utf8").trim().split(/\s+/).map(Number);
let p = 0;
const n = tokens[p++], k = tokens[p++];
const a = tokens.slice(p, p + n).sort((x, y) => x - y);
let minDiff = Infinity;
for (let i = 0; i + k - 1 < n; i++) {
    minDiff = Math.min(minDiff, a[i + k - 1] - a[i]);
}
console.log(minDiff === Infinity ? 0 : minDiff);
