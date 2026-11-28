// P000128 - Trapping Rain Water
const fs = require("fs");
const tokens = fs.readFileSync(0, "utf8").trim().split(/\s+/).map(Number);
let p = 0;
const n = tokens[p++];
const h = tokens.slice(p, p + n);
const leftMax = Array(n).fill(0);
const rightMax = Array(n).fill(0);
for (let i = 0; i < n; i++) leftMax[i] = Math.max(i > 0 ? leftMax[i - 1] : 0, h[i]);
for (let i = n - 1; i >= 0; i--) rightMax[i] = Math.max(i + 1 < n ? rightMax[i + 1] : 0, h[i]);
let water = 0;
for (let i = 0; i < n; i++) water += Math.min(leftMax[i], rightMax[i]) - h[i];
console.log(water);
