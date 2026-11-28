// P000180 - Find All Elements Appearing More Than N/3 Times
const fs = require("fs");
const tokens = fs.readFileSync(0, "utf8").trim().split(/\s+/).map(Number);
let p = 0;
const n = tokens[p++];
const a = tokens.slice(p, p + n);
const count = new Map();
for (const x of a) count.set(x, (count.get(x) || 0) + 1);
const res = [];
for (const [k, v] of count.entries()) {
    if (v > Math.floor(n / 3)) res.push(k);
}
console.log(res.sort((x, y) => x - y).join(" "));
