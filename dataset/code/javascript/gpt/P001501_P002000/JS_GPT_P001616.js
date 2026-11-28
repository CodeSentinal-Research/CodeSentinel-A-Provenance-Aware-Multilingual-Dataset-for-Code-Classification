const fs = require("fs");
const d = fs.readFileSync(0, "utf8").trim().split(/\s+/).map(Number);
let p = 0;
const n = d[p++], m = d[p++];
const pref = Array.from({ length: n + 1 }, () => new Array(m + 1).fill(0));
for (let i = 1; i <= n; i++) {
    for (let j = 1; j <= m; j++) {
        const x = d[p++];
        pref[i][j] = x + pref[i - 1][j] + pref[i][j - 1] - pref[i - 1][j - 1];
    }
}
const q = d[p++];
const out = [];
for (let z = 0; z < q; z++) {
    const r1 = d[p++], c1 = d[p++], r2 = d[p++], c2 = d[p++];
    out.push(String(
        pref[r2 + 1][c2 + 1] - pref[r1][c2 + 1] -
        pref[r2 + 1][c1] + pref[r1][c1]
    ));
}
console.log(out.join("\n"));
