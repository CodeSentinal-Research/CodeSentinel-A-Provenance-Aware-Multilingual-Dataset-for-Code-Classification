// P000133 - Rearrange Array Alternately
const fs = require("fs");
const tokens = fs.readFileSync(0, "utf8").trim().split(/\s+/).map(Number);
let p = 0;
const n = tokens[p++];
const a = tokens.slice(p, p + n);
let lo = 0, hi = n - 1;
const out = [];
while (lo <= hi) {
    out.push(a[hi--]);
    if (lo <= hi) out.push(a[lo++]);
}
console.log(out.join(" "));
