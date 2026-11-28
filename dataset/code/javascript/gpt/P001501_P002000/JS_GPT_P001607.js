const fs = require("fs");
const d = fs.readFileSync(0, "utf8").trim().split(/\s+/).map(Number);
let p = 0;
const n = d[p++];
const first = new Map([[0, 0]]);
let balance = 0;
let best = 0;
for (let i = 1; i <= n; i++) {
    balance += d[p++] === 1 ? 1 : -1;
    if (first.has(balance)) best = Math.max(best, i - first.get(balance));
    else first.set(balance, i);
}
console.log(best);
