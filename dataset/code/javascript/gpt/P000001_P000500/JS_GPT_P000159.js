// P000159 - Smallest Sum Contiguous Subarray
const fs = require("fs");
const tokens = fs.readFileSync(0, "utf8").trim().split(/\s+/).map(Number);
let p = 0;
const n = tokens[p++];
const a = tokens.slice(p, p + n);
let minSoFar = a[0], current = a[0];
for (let i = 1; i < n; i++) {
    current = Math.min(a[i], current + a[i]);
    minSoFar = Math.min(minSoFar, current);
}
console.log(minSoFar);
