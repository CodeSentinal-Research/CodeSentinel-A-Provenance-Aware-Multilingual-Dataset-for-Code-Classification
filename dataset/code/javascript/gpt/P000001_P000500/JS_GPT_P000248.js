// P000248 - Add Two Matrices
const fs = require("fs");
const tokens = fs.readFileSync(0, "utf8").trim().split(/\s+/).map(Number);
let p = 0;
const r = tokens[p++], c = tokens[p++];
const a = Array.from({length: r}, () => tokens.slice(p, p += c));
const b = Array.from({length: r}, () => tokens.slice(p, p += c));
for (let i = 0; i < r; i++) {
    const row = [];
    for (let j = 0; j < c; j++) row.push(a[i][j] + b[i][j]);
    console.log(row.join(" "));
}
