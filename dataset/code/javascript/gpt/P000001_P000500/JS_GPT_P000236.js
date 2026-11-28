// P000236 - Find Specific Pair in Matrix
const fs = require("fs");
const tokens = fs.readFileSync(0, "utf8").trim().split(/\s+/).map(Number);
let p = 0;
const n = tokens[p++];
const a = Array.from({length: n}, () => tokens.slice(p, p += n));
let ans = -Infinity;
for (let a1 = 0; a1 < n; a1++) {
    for (let b1 = 0; b1 < n; b1++) {
        for (let c1 = a1 + 1; c1 < n; c1++) {
            for (let d1 = b1 + 1; d1 < n; d1++) {
                ans = Math.max(ans, a[c1][d1] - a[a1][b1]);
            }
        }
    }
}
console.log(ans);
