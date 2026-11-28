const fs = require("fs");
const d = fs.readFileSync(0, "utf8").trim().split(/\s+/);
let p = 0;
const n = Number(d[p++]);
const k = BigInt(d[p++]);
const first = new Map([["0", 0]]);
let sum = 0n;
let best = 0;
for (let i = 1; i <= n; i++) {
    sum += BigInt(d[p++]);
    const key = (sum - k).toString();
    if (first.has(key)) best = Math.max(best, i - first.get(key));
    const s = sum.toString();
    if (!first.has(s)) first.set(s, i);
}
console.log(best);
