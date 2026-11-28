const fs = require("fs");
const d = fs.readFileSync(0, "utf8").trim().split(/\s+/).map(Number);
let p = 0;
const n = d[p++];
let a = 0;
let b = 0;
let maxDeficit = 0;
for (let i = 0; i < n; i++) {
    a += d[p++];
    b += d[n + 1 + i];
    maxDeficit = Math.max(maxDeficit, b - a);
}
console.log(maxDeficit);
