// P000160 - Find Pair with Given Sum
const fs = require("fs");
const tokens = fs.readFileSync(0, "utf8").trim().split(/\s+/).map(Number);
let p = 0;
const n = tokens[p++], target = tokens[p++];
const a = tokens.slice(p, p + n);
const seen = new Set();
let found = false;
for (const x of a) {
    if (seen.has(target - x)) { found = true; break; }
    seen.add(x);
}
console.log(found ? "Yes" : "No");
