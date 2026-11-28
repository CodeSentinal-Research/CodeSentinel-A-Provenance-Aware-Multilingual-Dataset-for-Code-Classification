const fs = require("fs");
const d = fs.readFileSync(0, "utf8").trim().split(/\s+/).map(Number);
let p = 0;
const n = d[p++], x = d[p++];
let sum = 0;
let answer = -1;
for (let i = 1; i <= n; i++) {
    sum += d[p++];
    if (answer === -1 && sum >= x) answer = i;
}
console.log(answer);
