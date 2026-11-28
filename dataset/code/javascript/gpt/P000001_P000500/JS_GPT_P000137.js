// P000137 - Find the Duplicate Number
const fs = require("fs");
const tokens = fs.readFileSync(0, "utf8").trim().split(/\s+/).map(Number);
let p = 0;
const n = tokens[p++];
const a = tokens.slice(p, p + n + 1);
const seen = new Set();
let dup = -1;
for (const x of a) {
    if (seen.has(x)) { dup = x; break; }
    seen.add(x);
}
console.log(dup);
