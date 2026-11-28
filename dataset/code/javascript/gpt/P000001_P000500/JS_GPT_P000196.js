// P000196 - Find Largest Sum of Contiguous Subarray of Size K
const fs = require("fs");
const tokens = fs.readFileSync(0, "utf8").trim().split(/\s+/).map(Number);
let p = 0;
const n = tokens[p++], k = tokens[p++];
const a = tokens.slice(p, p + n);
let sum = a.slice(0, k).reduce((s, x) => s + x, 0);
let best = sum;
for (let i = k; i < n; i++) {
    sum += a[i] - a[i - k];
    best = Math.max(best, sum);
}
console.log(best);
