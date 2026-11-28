// P000144 - Set Matrix Zeroes
const fs = require("fs");
const tokens = fs.readFileSync(0, "utf8").trim().split(/\s+/).map(Number);
let p = 0;
const rows = tokens[p++], cols = tokens[p++];
const mat = Array.from({length: rows}, () => tokens.slice(p, p += cols));
const zeroRows = new Set(), zeroCols = new Set();
for (let i = 0; i < rows; i++) {
    for (let j = 0; j < cols; j++) {
        if (mat[i][j] === 0) { zeroRows.add(i); zeroCols.add(j); }
    }
}
for (let i = 0; i < rows; i++) {
    for (let j = 0; j < cols; j++) {
        if (zeroRows.has(i) || zeroCols.has(j)) mat[i][j] = 0;
    }
}
for (const row of mat) console.log(row.join(" "));
