// P000132 - Equilibrium Index
const fs = require("fs");
const tokens = fs.readFileSync(0, "utf8").trim().split(/\s+/).map(Number);
let p = 0;
const n = tokens[p++];
const a = tokens.slice(p, p + n);
const total = a.reduce((s, x) => s + x, 0);
let left = 0, answer = -1;
for (let i = 0; i < n; i++) {
    if (left === total - left - a[i]) { answer = i; break; }
    left += a[i];
}
console.log(answer);
