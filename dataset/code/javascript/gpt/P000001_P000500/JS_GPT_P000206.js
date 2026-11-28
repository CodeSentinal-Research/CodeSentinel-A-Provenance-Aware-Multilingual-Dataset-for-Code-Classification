// P000206 - Find Median of Two Sorted Arrays of Different Sizes
const fs = require("fs");
const tokens = fs.readFileSync(0, "utf8").trim().split(/\s+/).map(Number);
let p = 0;
const m = tokens[p++], n = tokens[p++];
const a = tokens.slice(p, p + m); p += m;
const b = tokens.slice(p, p + n);
const merged = a.concat(b).sort((x, y) => x - y);
const len = merged.length;
const mid = Math.floor(len / 2);
console.log(len % 2 ? merged[mid] : (merged[mid - 1] + merged[mid]) / 2);
