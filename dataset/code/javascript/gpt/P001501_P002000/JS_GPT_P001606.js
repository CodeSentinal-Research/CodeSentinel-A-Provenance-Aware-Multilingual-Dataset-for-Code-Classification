const fs = require("fs");
const d = fs.readFileSync(0, "utf8").trim().split(/\s+/).map(Number);
let p = 0;
const n = d[p++];
const freq = new Map([[0, 1]]);
let balance = 0;
let answer = 0;
for (let i = 0; i < n; i++) {
    balance += d[p++] === 1 ? 1 : -1;
    answer += freq.get(balance) || 0;
    freq.set(balance, (freq.get(balance) || 0) + 1);
}
console.log(answer);
