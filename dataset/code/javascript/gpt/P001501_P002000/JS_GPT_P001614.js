const fs = require("fs");
const d = fs.readFileSync(0, "utf8").trim().split(/\s+/).map(Number);
let p = 0;
const n = d[p++], m = d[p++];
const a = Array.from({ length: n }, () => {
    const row = d.slice(p, p + m);
    p += m;
    return row;
});
let best = -Infinity;
for (let top = 0; top < n; top++) {
    const col = new Array(m).fill(0);
    for (let bottom = top; bottom < n; bottom++) {
        for (let j = 0; j < m; j++) col[j] += a[bottom][j];
        let cur = col[0];
        let rowBest = col[0];
        for (let j = 1; j < m; j++) {
            cur = Math.max(col[j], cur + col[j]);
            rowBest = Math.max(rowBest, cur);
        }
        best = Math.max(best, rowBest);
    }
}
console.log(best);
