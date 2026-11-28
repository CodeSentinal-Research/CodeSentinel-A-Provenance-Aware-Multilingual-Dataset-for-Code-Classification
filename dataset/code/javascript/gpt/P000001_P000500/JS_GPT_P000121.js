// P000121 - Find Majority Element
const fs = require("fs");
const tokens = fs.readFileSync(0, "utf8").trim().split(/\s+/).map(Number);
let p = 0;
const n = tokens[p++];
const a = tokens.slice(p, p + n);
let candidate = 0, count = 0;
for (const x of a) {
    if (count === 0) candidate = x;
    count += (x === candidate ? 1 : -1);
}
let total = 0;
for (const x of a) if (x === candidate) total++;
console.log(total > Math.floor(n / 2) ? candidate : -1);
