// P000167 - Longest Increasing Subarray
const fs = require("fs");
const tokens = fs.readFileSync(0, "utf8").trim().split(/\s+/).map(Number);
let p = 0;
const n = tokens[p++];
const a = tokens.slice(p, p + n);
let best = 1, run = 1;
for (let i = 1; i < n; i++) {
    run = (a[i] > a[i - 1]) ? run + 1 : 1;
    best = Math.max(best, run);
}
console.log(best);
