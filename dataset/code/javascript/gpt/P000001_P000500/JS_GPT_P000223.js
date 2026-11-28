// P000223 - Activity Selection Problem
const fs = require("fs");
const tokens = fs.readFileSync(0, "utf8").trim().split(/\s+/).map(Number);
let p = 0;
const n = tokens[p++];
const acts = [];
for (let i = 0; i < n; i++) acts.push([tokens[p++], tokens[p++]]);
acts.sort((a, b) => a[1] - b[1]);
let count = 0, curEnd = -Infinity;
for (const [s, f] of acts) {
    if (s >= curEnd) { count++; curEnd = f; }
}
console.log(count);
