// P000162 - Count Pairs with Given Sum
const fs = require("fs");
const tokens = fs.readFileSync(0, "utf8").trim().split(/\s+/).map(Number);
let p = 0;
const n = tokens[p++], target = tokens[p++];
const a = tokens.slice(p, p + n);
const freq = new Map();
let total = 0;
for (const x of a) {
    total += freq.get(target - x) || 0;
    freq.set(x, (freq.get(x) || 0) + 1);
}
console.log(total);
