const fs = require("fs");
const d = fs.readFileSync(0, "utf8").trim().split(/\s+/).map(Number);
let p = 0;
const n = d[p++], m = d[p++], k = d[p++];
const pref = Array.from({ length: n + 1 }, () => new Array(m + 1).fill(0));
for (let i = 1; i <= n; i++) {
    for (let j = 1; j <= m; j++) {
        const x = d[p++];
        pref[i][j] = x + pref[i - 1][j] + pref[i][j - 1] - pref[i - 1][j - 1];
    }
}
const out = [];
for (let i = 1; i <= n; i++) {
    const row = [];
    const r1 = Math.max(1, i - k), r2 = Math.min(n, i + k);
    for (let j = 1; j <= m; j++) {
        const c1 = Math.max(1, j - k), c2 = Math.min(m, j + k);
        row.push(
            pref[r2][c2] - pref[r1 - 1][c2] -
            pref[r2][c1 - 1] + pref[r1 - 1][c1 - 1]
        );
    }
    out.push(row.join(" "));
}
console.log(out.join("\n"));
