// P000187 - Find the Smallest Positive Missing Number
const fs = require("fs");
const tokens = fs.readFileSync(0, "utf8").trim().split(/\s+/).map(Number);
let p = 0;
const n = tokens[p++];
const a = tokens.slice(p, p + n);
const set = new Set(a);
let ans = 1;
while (set.has(ans)) ans++;
console.log(ans);
