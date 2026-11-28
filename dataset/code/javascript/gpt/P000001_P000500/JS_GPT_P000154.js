// P000154 - Find the Missing and Repeating Number
const fs = require("fs");
const tokens = fs.readFileSync(0, "utf8").trim().split(/\s+/).map(Number);
let p = 0;
const n = tokens[p++];
const a = tokens.slice(p, p + n);
const count = Array(n + 1).fill(0);
for (const x of a) if (x >= 1 && x <= n) count[x]++;
let missing = -1, repeating = -1;
for (let i = 1; i <= n; i++) {
    if (count[i] === 0) missing = i;
    if (count[i] > 1) repeating = i;
}
console.log(`${missing} ${repeating}`);
