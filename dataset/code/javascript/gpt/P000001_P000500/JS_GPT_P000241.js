// P000241 - Find Saddle Point in Matrix
const fs = require("fs");
const tokens = fs.readFileSync(0, "utf8").trim().split(/\s+/).map(Number);
let p = 0;
const n = tokens[p++];
const a = Array.from({length: n}, () => tokens.slice(p, p += n));
let ans = null;
for (let i = 0; i < n; i++) {
    const minRow = Math.min(...a[i]);
    const j = a[i].indexOf(minRow);
    let isMaxCol = true;
    for (let k = 0; k < n; k++) {
        if (a[k][j] > minRow) { isMaxCol = false; break; }
    }
    if (isMaxCol) { ans = minRow; break; }
}
console.log(ans !== null ? ans : "No Saddle Point");
