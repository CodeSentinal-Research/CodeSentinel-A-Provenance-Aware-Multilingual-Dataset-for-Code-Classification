const fs = require("fs");
const d = fs.readFileSync(0, "utf8").trim().split(/\s+/).map(Number);
let p = 0;
const n = d[p++];
let sum = 0;
let answer = 0;
for (let i = 0; i < n; i++) {
    sum += d[p++];
    if (sum > 0) answer++;
}
console.log(answer);
