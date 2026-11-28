const fs = require("fs");
const d = fs.readFileSync(0, "utf8").trim().split(/\s+/);
let p = 0;
const n = Number(d[p++]), m = Number(d[p++]), target = Number(d[p++]);
const grid = Array.from({ length: n }, () => {
    const row = d.slice(p, p + m).map(Number);
    p += m;
    return row;
});

let prev = Array.from({ length: m }, () => new Map());
prev[0].set(grid[0][0], 1n);
for (let c = 1; c < m; c++) {
    for (const [sum, ways] of prev[c - 1]) {
        const ns = sum + grid[0][c];
        prev[c].set(ns, (prev[c].get(ns) || 0n) + ways);
    }
}

for (let r = 1; r < n; r++) {
    const cur = Array.from({ length: m }, () => new Map());
    for (let c = 0; c < m; c++) {
        if (c > 0) {
            for (const [sum, ways] of cur[c - 1]) {
                const ns = sum + grid[r][c];
                cur[c].set(ns, (cur[c].get(ns) || 0n) + ways);
            }
        }
        for (const [sum, ways] of prev[c]) {
            const ns = sum + grid[r][c];
            cur[c].set(ns, (cur[c].get(ns) || 0n) + ways);
        }
    }
    prev = cur;
}
console.log((prev[m - 1].get(target) || 0n).toString());
