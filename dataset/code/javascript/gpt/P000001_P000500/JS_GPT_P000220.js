// P000220 - Find the Celebrity
const fs = require("fs");
const tokens = fs.readFileSync(0, "utf8").trim().split(/\s+/).map(Number);
let p = 0;
const n = tokens[p++];
const mat = Array.from({length: n}, () => tokens.slice(p, p += n));
let cand = 0;
for (let i = 1; i < n; i++) {
    if (mat[cand][i] === 1) cand = i;
}
let ok = true;
for (let i = 0; i < n; i++) {
    if (i !== cand) {
        if (mat[cand][i] === 1 || mat[i][cand] === 0) { ok = false; break; }
    }
}
console.log(ok ? cand : -1);
