// P000184 - Longest Subarray with Sum K
const fs = require("fs");
const tokens = fs.readFileSync(0, "utf8").trim().split(/\s+/).map(Number);
let p = 0;
const n = tokens[p++], k = tokens[p++];
const a = tokens.slice(p, p + n);
const map = new Map();
map.set(0, -1);
let sum = 0, maxLen = 0;
for (let i = 0; i < n; i++) {
    sum += a[i];
    if (map.has(sum - k)) maxLen = Math.max(maxLen, i - map.get(sum - k));
    if (!map.has(sum)) map.set(sum, i);
}
console.log(maxLen);
