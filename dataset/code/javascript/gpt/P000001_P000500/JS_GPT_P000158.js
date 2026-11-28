// P000158 - Largest Sum Contiguous Increasing Subarray
const fs = require("fs");
const tokens = fs.readFileSync(0, "utf8").trim().split(/\s+/).map(Number);
let p = 0;
const n = tokens[p++];
const a = tokens.slice(p, p + n);
let maxSoFar = a[0], current = a[0];
for (let i = 1; i < n; i++) {
    if (a[i] > a[i - 1]) current += a[i];
    else current = a[i];
    maxSoFar = Math.max(maxSoFar, current);
}
console.log(maxSoFar);
