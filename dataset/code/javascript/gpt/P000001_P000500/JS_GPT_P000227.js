// P000227 - Maximum Sum Rectangle in 2D Matrix
const fs = require("fs");
const tokens = fs.readFileSync(0, "utf8").trim().split(/\s+/).map(Number);
let p = 0;
const r = tokens[p++], c = tokens[p++];
const a = Array.from({length: r}, () => tokens.slice(p, p += c));
let best = -Infinity;
for (let l = 0; l < c; l++) {
    const col = Array(r).fill(0);
    for (let right = l; right < c; right++) {
        for (let i = 0; i < r; i++) col[i] += a[i][right];
        let cur = col[0], maxKadane = col[0];
        for (let i = 1; i < r; i++) {
            cur = Math.max(col[i], cur + col[i]);
            maxKadane = Math.max(maxKadane, cur);
        }
        best = Math.max(best, maxKadane);
    }
}
console.log(best);
