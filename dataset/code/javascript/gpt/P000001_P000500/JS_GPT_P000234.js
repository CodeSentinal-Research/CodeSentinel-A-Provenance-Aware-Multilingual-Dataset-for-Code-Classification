// P000234 - Boolean Matrix
const fs = require("fs");
const tokens = fs.readFileSync(0, "utf8").trim().split(/\s+/).map(Number);
let p = 0;
const r = tokens[p++], c = tokens[p++];
const a = Array.from({length: r}, () => tokens.slice(p, p += c));
const zr = new Set(), zc = new Set();
for (let i = 0; i < r; i++) {
    for (let j = 0; j < c; j++) {
        if (a[i][j] === 0) { zr.add(i); zc.add(j); }
    }
}
for (let i = 0; i < r; i++) {
    const row = [];
    for (let j = 0; j < c; j++) row.push((zr.has(i) || zc.has(j)) ? 0 : a[i][j]);
    console.log(row.join(" "));
}
