// P000216 - Degree of an Array
const fs = require("fs");
const tokens = fs.readFileSync(0, "utf8").trim().split(/\s+/).map(Number);
let p = 0;
const n = tokens[p++];
const a = tokens.slice(p, p + n);
const count = new Map(), first = new Map(), last = new Map();
for (let i = 0; i < n; i++) {
    const x = a[i];
    count.set(x, (count.get(x) || 0) + 1);
    if (!first.has(x)) first.set(x, i);
    last.set(x, i);
}
const degree = Math.max(...count.values());
let minLen = n;
for (const [x, freq] of count.entries()) {
    if (freq === degree) {
        minLen = Math.min(minLen, last.get(x) - first.get(x) + 1);
    }
}
console.log(minLen);
