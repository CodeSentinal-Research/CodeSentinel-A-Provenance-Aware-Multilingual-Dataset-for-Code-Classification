// P000205 - Find Median of Two Sorted Arrays of Same Size
const fs = require("fs");
const tokens = fs.readFileSync(0, "utf8").trim().split(/\s+/).map(Number);
let p = 0;
const n = tokens[p++];
const a = tokens.slice(p, p + n); p += n;
const b = tokens.slice(p, p + n);
const merged = a.concat(b).sort((x, y) => x - y);
const left = merged[n - 1], right = merged[n];
console.log((left + right) / 2);
