// P000152 - Find Minimum Product of Two Elements
const fs = require("fs");
const tokens = fs.readFileSync(0, "utf8").trim().split(/\s+/).map(Number);
let p = 0;
const n = tokens[p++];
const a = tokens.slice(p, p + n).sort((x, y) => x - y);
let minProd = Infinity;
for (let i = 0; i < n; i++) {
    for (let j = i + 1; j < n; j++) {
        minProd = Math.min(minProd, a[i] * a[j]);
    }
}
console.log(minProd);
