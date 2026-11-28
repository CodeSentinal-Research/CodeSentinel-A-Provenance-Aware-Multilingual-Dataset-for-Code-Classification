// P000185 - Longest Subarray with Equal 0s and 1s
const fs = require("fs");
const tokens = fs.readFileSync(0, "utf8").trim().split(/\s+/).map(Number);
let p = 0;
const n = tokens[p++];
const a = tokens.slice(p, p + n);
const map = new Map();
map.set(0, -1);
let sum = 0, maxLen = 0;
for (let i = 0; i < n; i++) {
    sum += (a[i] === 0 ? -1 : 1);
    if (map.has(sum)) maxLen = Math.max(maxLen, i - map.get(sum));
    else map.set(sum, i);
}
console.log(maxLen);
