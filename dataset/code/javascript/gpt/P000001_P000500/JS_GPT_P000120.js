// P000120 - Find Peak Element
const fs = require("fs");
const tokens = fs.readFileSync(0, "utf8").trim().split(/\s+/).map(Number);
let p = 0;
const n = tokens[p++];
const a = tokens.slice(p, p + n);
let peak = 0;
for (let i = 0; i < n; i++) {
    const left = i > 0 ? a[i - 1] : -Infinity;
    const right = i < n - 1 ? a[i + 1] : -Infinity;
    if (a[i] >= left && a[i] >= right) { peak = i; break; }
}
console.log(peak);
