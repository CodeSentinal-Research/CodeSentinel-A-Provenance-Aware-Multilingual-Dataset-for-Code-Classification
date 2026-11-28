const fs = require("fs");
const d = fs.readFileSync(0, "utf8").trim().split(/\s+/);
let p = 0;
const n = Number(d[p++]);
const a = new Array(n);
let total = 0n;
for (let i = 0; i < n; i++) {
    a[i] = BigInt(d[p++]);
    total += a[i];
}
if (total % 3n !== 0n) {
    console.log(0);
    process.exit(0);
}
const target = total / 3n;
let sum = 0n;
let firstParts = 0n;
let answer = 0n;
for (let i = 0; i < n - 1; i++) {
    sum += a[i];
    if (sum === target) firstParts++;
    if (i < n - 1 && sum === target * 2n) answer += firstParts;
}
console.log(answer.toString());
