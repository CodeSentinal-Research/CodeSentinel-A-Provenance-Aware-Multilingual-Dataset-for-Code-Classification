// P000208 - Print Matrix in Diagonal Order
const fs = require("fs");
const tokens = fs.readFileSync(0, "utf8").trim().split(/\s+/).map(Number);
let p = 0;
const r = tokens[p++], c = tokens[p++];
const a = Array.from({length: r}, () => tokens.slice(p, p += c));
const out = [];
for (let d = 0; d < r + c - 1; d++) {
    const cur = [];
    for (let i = 0; i < r; i++) {
        const j = d - i;
        if (j >= 0 && j < c) cur.push(a[i][j]);
    }
    if (d % 2 !== 0) cur.reverse();
    for (const v of cur) out.push(v);
}
console.log(out.join(" "));
