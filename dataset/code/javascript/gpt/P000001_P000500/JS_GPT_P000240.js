// P000240 - Sum of Boundary Elements
const fs = require("fs");
const tokens = fs.readFileSync(0, "utf8").trim().split(/\s+/).map(Number);
let p = 0;
const r = tokens[p++], c = tokens[p++];
const a = Array.from({length: r}, () => tokens.slice(p, p += c));
let sum = 0;
for (let i = 0; i < r; i++) {
    for (let j = 0; j < c; j++) {
        if (i === 0 || i === r - 1 || j === 0 || j === c - 1) sum += a[i][j];
    }
}
console.log(sum);
