// P000122 - Maximum Subarray Sum (Kadane)
const fs = require("fs");
const tokens = fs.readFileSync(0, "utf8").trim().split(/\s+/).map(Number);
let p = 0;
const n = tokens[p++];
const a = tokens.slice(p, p + n);
let maxSoFar = a[0], currentMax = a[0];
for (let i = 1; i < n; i++) {
    currentMax = Math.max(a[i], currentMax + a[i]);
    maxSoFar = Math.max(maxSoFar, currentMax);
}
console.log(maxSoFar);
