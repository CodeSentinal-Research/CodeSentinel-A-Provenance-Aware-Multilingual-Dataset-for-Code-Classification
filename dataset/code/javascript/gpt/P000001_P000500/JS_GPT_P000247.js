// P000247 - Check if Two Matrices are Identical
const fs = require("fs");
const tokens = fs.readFileSync(0, "utf8").trim().split(/\s+/).map(Number);
let p = 0;
const r = tokens[p++], c = tokens[p++];
const a = Array.from({length: r}, () => tokens.slice(p, p += c));
const b = Array.from({length: r}, () => tokens.slice(p, p += c));
let identical = true;
for (let i = 0; i < r; i++) {
    for (let j = 0; j < c; j++) {
        if (a[i][j] !== b[i][j]) { identical = false; break; }
    }
    if (!identical) break;
}
console.log(identical ? "Identical" : "Not Identical");
