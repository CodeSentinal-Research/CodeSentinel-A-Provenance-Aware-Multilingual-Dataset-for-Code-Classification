const fs = require("fs");
const d = fs.readFileSync(0, "utf8").trim().split(/\s+/).map(Number);
let p = 0;
const n = d[p++], k = d[p++];
const freq = new Map([[0, 1]]);
let sum = 0;
let answer = 0;
for (let i = 0; i < n; i++) {
    sum += d[p++];
    const rem = ((sum % k) + k) % k;
    answer += freq.get(rem) || 0;
    freq.set(rem, (freq.get(rem) || 0) + 1);
}
console.log(answer);
