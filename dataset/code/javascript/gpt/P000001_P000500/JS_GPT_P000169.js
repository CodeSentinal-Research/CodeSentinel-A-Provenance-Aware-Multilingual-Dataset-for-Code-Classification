// P000169 - Find the First Repeating Element
const fs = require("fs");
const tokens = fs.readFileSync(0, "utf8").trim().split(/\s+/).map(Number);
let p = 0;
const n = tokens[p++];
const a = tokens.slice(p, p + n);
const seen = new Set();
let answer = -1;
for (const x of a) {
    if (seen.has(x)) { answer = x; break; }
    seen.add(x);
}
console.log(answer);
