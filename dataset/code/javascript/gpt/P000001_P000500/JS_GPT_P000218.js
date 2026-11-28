// P000218 - Majority Element II
const fs = require("fs");
const tokens = fs.readFileSync(0, "utf8").trim().split(/\s+/).map(Number);
let p = 0;
const n = tokens[p++];
const a = tokens.slice(p, p + n);
let cand1 = 0, cand2 = 0, count1 = 0, count2 = 0;
for (const x of a) {
    if (x === cand1) count1++;
    else if (x === cand2) count2++;
    else if (count1 === 0) { cand1 = x; count1 = 1; }
    else if (count2 === 0) { cand2 = x; count2 = 1; }
    else { count1--; count2--; }
}
count1 = 0; count2 = 0;
for (const x of a) {
    if (x === cand1) count1++;
    else if (x === cand2) count2++;
}
const res = [];
if (count1 > Math.floor(n / 3)) res.push(cand1);
if (count2 > Math.floor(n / 3) && cand2 !== cand1) res.push(cand2);
console.log(res.sort((x, y) => x - y).join(" "));
