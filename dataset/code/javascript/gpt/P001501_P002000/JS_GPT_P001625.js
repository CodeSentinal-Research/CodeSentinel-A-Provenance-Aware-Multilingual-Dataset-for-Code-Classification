const fs = require("fs");
const d = fs.readFileSync(0, "utf8").trim().split(/\s+/).map(Number);
let p = 0;
const n = d[p++], m = d[p++];
const pref = Array.from({ length: n }, () => new Array(m).fill(0));
for (let i = 0; i < n; i++) {
    for (let j = 0; j < m; j++) {
        const x = d[p++];
        pref[i][j] = x +
            (i > 0 ? pref[i - 1][j] : 0) +
            (j > 0 ? pref[i][j - 1] : 0) -
            (i > 0 && j > 0 ? pref[i - 1][j - 1] : 0);
    }
}
console.log(pref.map(row => row.join(" ")).join("\n"));
