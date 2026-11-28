// P000202 - Longest Consecutive Sequence
const fs = require("fs");
const tokens = fs.readFileSync(0, "utf8").trim().split(/\s+/).map(Number);
let p = 0;
const n = tokens[p++];
const a = tokens.slice(p, p + n);
const set = new Set(a);
let best = 0;
for (const x of set) {
    if (!set.has(x - 1)) {
        let y = x, len = 1;
        while (set.has(y + 1)) { y++; len++; }
        best = Math.max(best, len);
    }
}
console.log(best);
