// P000239 - Boundary Elements of Matrix
const fs = require("fs");
const tokens = fs.readFileSync(0, "utf8").trim().split(/\s+/).map(Number);
let p = 0;
const r = tokens[p++], c = tokens[p++];
const a = Array.from({length: r}, () => tokens.slice(p, p += c));
const out = [];
for (let j = 0; j < c; j++) out.push(a[0][j]);
for (let i = 1; i < r; i++) out.push(a[i][c - 1]);
if (r > 1) {
    for (let j = c - 2; j >= 0; j--) out.push(a[r - 1][j]);
}
if (c > 1) {
    for (let i = r - 2; i > 0; i--) out.push(a[i][0]);
}
console.log(out.join(" "));
