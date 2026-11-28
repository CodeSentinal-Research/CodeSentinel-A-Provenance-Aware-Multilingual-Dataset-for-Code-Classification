// P000157 - Find Equilibrium Point
const fs = require("fs");
const tokens = fs.readFileSync(0, "utf8").trim().split(/\s+/).map(Number);
let p = 0;
const n = tokens[p++];
const a = tokens.slice(p, p + n);
const total = a.reduce((s, x) => s + x, 0);
let left = 0, ans = -1;
for (let i = 0; i < n; i++) {
    if (left === total - left - a[i]) { ans = i + 1; break; }
    left += a[i];
}
console.log(ans);
