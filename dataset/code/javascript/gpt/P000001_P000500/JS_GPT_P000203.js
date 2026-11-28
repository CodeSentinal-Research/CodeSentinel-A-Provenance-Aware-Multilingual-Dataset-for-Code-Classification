// P000203 - Find the Maximum Repeating Number
const fs = require("fs");
const tokens = fs.readFileSync(0, "utf8").trim().split(/\s+/).map(Number);
let p = 0;
const n = tokens[p++], k = tokens[p++];
const a = tokens.slice(p, p + n);
const freq = Array(k).fill(0);
for (const x of a) if (x >= 0 && x < k) freq[x]++;
let answer = 0;
for (let x = 1; x < k; x++) {
    if (freq[x] > freq[answer] || (freq[x] === freq[answer] && x > answer)) answer = x;
}
console.log(answer);
