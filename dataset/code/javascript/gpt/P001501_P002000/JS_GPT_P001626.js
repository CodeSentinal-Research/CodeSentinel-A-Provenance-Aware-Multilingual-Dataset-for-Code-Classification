const fs = require("fs");
const d = fs.readFileSync(0, "utf8").trim().split(/\s+/).map(Number);
let p = 0;
const n = d[p++], m = d[p++], threshold = d[p++];
const a = Array.from({ length: n }, () => {
    const row = d.slice(p, p + m);
    p += m;
    return row;
});

const pref = Array.from({ length: n + 1 }, () => new Array(m + 1).fill(0));
for (let i = 0; i < n; i++) {
    for (let j = 0; j < m; j++) {
        pref[i + 1][j + 1] = a[i][j] + pref[i][j + 1] +
            pref[i + 1][j] - pref[i][j];
    }
}

function squareSum(r, c, len) {
    const r2 = r + len, c2 = c + len;
    return pref[r2][c2] - pref[r][c2] - pref[r2][c] + pref[r][c];
}

function exists(len) {
    for (let r = 0; r + len <= n; r++) {
        for (let c = 0; c + len <= m; c++) {
            if (squareSum(r, c, len) <= threshold) return true;
        }
    }
    return false;
}

let lo = 0, hi = Math.min(n, m);
while (lo < hi) {
    const mid = Math.floor((lo + hi + 1) / 2);
    if (exists(mid)) lo = mid;
    else hi = mid - 1;
}
console.log(lo);
