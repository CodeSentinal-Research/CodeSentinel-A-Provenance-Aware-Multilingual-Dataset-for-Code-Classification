const fs = require("fs");
const d = fs.readFileSync(0, "utf8").trim().split(/\s+/).map(Number);
let p = 0;
const n = d[p++];
let sum = 0;
let answer = 0;
for (let i = 0; i < n; i++) {
    sum += d[p++];
    answer = Math.max(answer, Math.abs(sum));
}
console.log(answer);
