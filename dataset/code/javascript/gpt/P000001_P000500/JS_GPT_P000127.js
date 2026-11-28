// P000127 - Container With Most Water
const fs = require("fs");
const tokens = fs.readFileSync(0, "utf8").trim().split(/\s+/).map(Number);
let p = 0;
const n = tokens[p++];
const h = tokens.slice(p, p + n);
let left = 0, right = n - 1, best = 0;
while (left < right) {
    const area = Math.min(h[left], h[right]) * (right - left);
    if (area > best) best = area;
    if (h[left] < h[right]) left++;
    else right--;
}
console.log(best);
