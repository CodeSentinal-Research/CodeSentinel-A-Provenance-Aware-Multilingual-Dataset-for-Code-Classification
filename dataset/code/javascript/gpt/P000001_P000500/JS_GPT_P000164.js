// P000164 - Count Triplets with Given Sum
const fs = require("fs");
const tokens = fs.readFileSync(0, "utf8").trim().split(/\s+/).map(Number);
let p = 0;
const n = tokens[p++], target = tokens[p++];
const a = tokens.slice(p, p + n);
let count = 0;
for (let i = 0; i < n - 2; i++) {
    const freq = new Map();
    for (let k = i + 1; k < n; k++) freq.set(a[k], (freq.get(a[k]) || 0) + 1);
    for (let j = i + 1; j < n - 1; j++) {
        freq.set(a[j], freq.get(a[j]) - 1);
        const need = target - a[i] - a[j];
        count += (freq.get(need) || 0);
    }
}
console.log(count);
