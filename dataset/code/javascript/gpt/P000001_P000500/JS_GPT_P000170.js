// P000170 - Find the First Non-Repeating Element
const fs = require("fs");
const tokens = fs.readFileSync(0, "utf8").trim().split(/\s+/).map(Number);
let p = 0;
const n = tokens[p++];
const a = tokens.slice(p, p + n);
const count = new Map();
for (const x of a) count.set(x, (count.get(x) || 0) + 1);
let ans = -1;
for (const x of a) {
    if (count.get(x) === 1) { ans = x; break; }
}
console.log(ans);
