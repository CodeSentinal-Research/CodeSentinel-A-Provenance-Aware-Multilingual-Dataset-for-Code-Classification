// P000242 - Count Zeros in a Sorted Matrix
const fs = require("fs");
const tokens = fs.readFileSync(0, "utf8").trim().split(/\s+/).map(Number);
let p = 0;
const n = tokens[p++];
const a = Array.from({length: n}, () => tokens.slice(p, p += n));
let zeros = 0;
for (let i = 0; i < n; i++) {
    for (let j = 0; j < n; j++) if (a[i][j] === 0) zeros++;
}
console.log(zeros);
