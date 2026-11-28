// P000166 - Minimum Product Subarray
const fs = require("fs");
const tokens = fs.readFileSync(0, "utf8").trim().split(/\s+/).map(Number);
let p = 0;
const n = tokens[p++];
const a = tokens.slice(p, p + n);
let mx = a[0], mn = a[0], ans = a[0];
for (let i = 1; i < n; i++) {
    const x = a[i];
    if (x < 0) { const temp = mx; mx = mn; mn = temp; }
    mx = Math.max(x, mx * x);
    mn = Math.min(x, mn * x);
    ans = Math.min(ans, mn);
}
console.log(ans);
