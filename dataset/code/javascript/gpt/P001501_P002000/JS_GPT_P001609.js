const fs = require("fs");
const d = fs.readFileSync(0, "utf8").trim().split(/\s+/).map(Number);
let p = 0;
const n = d[p++];
const a = d.slice(p, p + n);
const total = a.reduce((s, x) => s + x, 0);
let left = 0;
let answer = 0;
for (const x of a) {
    if (left === total - left - x) answer++;
    left += x;
}
console.log(answer);
