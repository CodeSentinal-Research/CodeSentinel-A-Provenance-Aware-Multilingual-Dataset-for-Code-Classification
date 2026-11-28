// P000182 - Find the Most Frequent Element
const fs = require("fs");
const tokens = fs.readFileSync(0, "utf8").trim().split(/\s+/).map(Number);
let p = 0;
const n = tokens[p++];
const a = tokens.slice(p, p + n);
const count = new Map();
for (const x of a) count.set(x, (count.get(x) || 0) + 1);
let best = a[0], bestCount = 0;
for (const [k, v] of count.entries()) {
    if (v > bestCount || (v === bestCount && k < best)) {
        bestCount = v;
        best = k;
    }
}
console.log(best);
