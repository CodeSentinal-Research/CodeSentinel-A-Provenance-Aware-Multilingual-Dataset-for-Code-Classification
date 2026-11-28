// P000200 - Find Two Elements with Odd Occurrence
const fs = require("fs");
const tokens = fs.readFileSync(0, "utf8").trim().split(/\s+/).map(Number);
let p = 0;
const n = tokens[p++];
const a = tokens.slice(p, p + n);
let xor = 0;
for (const x of a) xor ^= x;
const setBit = xor & -xor;
let x = 0, y = 0;
for (const v of a) {
    if (v & setBit) x ^= v;
    else y ^= v;
}
const ans = [x, y].sort((a, b) => a - b);
console.log(ans.join(" "));
