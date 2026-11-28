// P000168 - Longest Decreasing Subarray
const fs = require("fs");
const tokens = fs.readFileSync(0, "utf8").trim().split(/\s+/).map(Number);
let p = 0;
const n = tokens[p++];
const a = tokens.slice(p, p + n);
let longest = 1, current = 1;
for (let i = 1; i < n; i++) {
    current = (a[i] < a[i - 1]) ? current + 1 : 1;
    longest = Math.max(longest, current);
}
console.log(longest);
