// P000189 - Maximum Circular Subarray Sum
const fs = require("fs");
const tokens = fs.readFileSync(0, "utf8").trim().split(/\s+/).map(Number);
let p = 0;
const n = tokens[p++];
const a = tokens.slice(p, p + n);
let maxKadane = a[0], curMax = a[0];
let minKadane = a[0], curMin = a[0];
let total = a[0];
for (let i = 1; i < n; i++) {
    curMax = Math.max(a[i], curMax + a[i]);
    maxKadane = Math.max(maxKadane, curMax);
    curMin = Math.min(a[i], curMin + a[i]);
    minKadane = Math.min(minKadane, curMin);
    total += a[i];
}
const maxCircular = total === minKadane ? maxKadane : Math.max(maxKadane, total - minKadane);
console.log(maxCircular);
