const fs = require("fs");
const d = fs.readFileSync(0, "utf8").trim().split(/\s+/);
let p = 0;
const n = Number(d[p++]);
const k = BigInt(d[p++]);
const freq = new Map([["0", 1]]);
let sum = 0n;
let answer = 0;
for (let i = 0; i < n; i++) {
    sum += BigInt(d[p++]);
    const key = (sum - k).toString();
    answer += freq.get(key) || 0;
    const s = sum.toString();
    freq.set(s, (freq.get(s) || 0) + 1);
}
console.log(answer);
