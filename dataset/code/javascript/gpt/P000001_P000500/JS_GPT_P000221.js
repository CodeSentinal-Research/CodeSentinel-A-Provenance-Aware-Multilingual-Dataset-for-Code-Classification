// P000221 - Maximum Length Chain of Pairs
const fs = require("fs");
const tokens = fs.readFileSync(0, "utf8").trim().split(/\s+/).map(Number);
let p = 0;
const n = tokens[p++];
const pairs = [];
for (let i = 0; i < n; i++) {
    pairs.push([tokens[p++], tokens[p++]]);
}
pairs.sort((a, b) => a[1] - b[1]);
let count = 0, curEnd = -Infinity;
for (const [s, e] of pairs) {
    if (s > curEnd) { count++; curEnd = e; }
}
console.log(count);
