// P000173 - Find Maximum Difference
const fs = require("fs");
const tokens = fs.readFileSync(0, "utf8").trim().split(/\s+/).map(Number);
let p = 0;
const n = tokens[p++];
const a = tokens.slice(p, p + n);
let small = a[0], best = a[1] - a[0];
for (let i = 1; i < n; i++) {
    best = Math.max(best, a[i] - small);
    small = Math.min(small, a[i]);
}
console.log(best);
