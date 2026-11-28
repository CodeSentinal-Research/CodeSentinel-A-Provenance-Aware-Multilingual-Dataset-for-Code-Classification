// P000165 - Maximum Product Subarray
const fs = require("fs");
const tokens = fs.readFileSync(0, "utf8").trim().split(/\s+/).map(Number);
let p = 0;
const n = tokens[p++];
const a = tokens.slice(p, p + n);
let hi = a[0], lo = a[0], best = a[0];
for (let i = 1; i < n; i++) {
    const x = a[i];
    if (x < 0) { const temp = hi; hi = lo; lo = temp; }
    hi = Math.max(x, hi * x);
    lo = Math.min(x, lo * x);
    best = Math.max(best, hi);
}
console.log(best);
