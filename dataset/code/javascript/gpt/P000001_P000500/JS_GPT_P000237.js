// P000237 - Rotate each Row of Matrix by K
const fs = require("fs");
const tokens = fs.readFileSync(0, "utf8").trim().split(/\s+/).map(Number);
let p = 0;
const r = tokens[p++], c = tokens[p++], k = tokens[p++];
const a = Array.from({length: r}, () => tokens.slice(p, p += c));
const shift = c ? (k % c) : 0;
for (let i = 0; i < r; i++) {
    const row = a[i];
    const rotated = shift ? row.slice(c - shift).concat(row.slice(0, c - shift)) : row;
    console.log(rotated.join(" "));
}
