// P000250 - Find Determinant of a Matrix
const fs = require("fs");
const tokens = fs.readFileSync(0, "utf8").trim().split(/\s+/).map(Number);
let p = 0;
const n = tokens[p++];
const a = Array.from({length: n}, () => tokens.slice(p, p += n));
let det = 1;
for (let i = 0; i < n; i++) {
    let pivot = i;
    for (let r = i + 1; r < n; r++) {
        if (Math.abs(a[r][i]) > Math.abs(a[pivot][i])) pivot = r;
    }
    if (Math.abs(a[pivot][i]) < 1e-12) { det = 0; break; }
    if (pivot !== i) {
        [a[i], a[pivot]] = [a[pivot], a[i]];
        det = -det;
    }
    det *= a[i][i];
    for (let r = i + 1; r < n; r++) {
        const factor = a[r][i] / a[i][i];
        for (let j = i + 1; j < n; j++) a[r][j] -= factor * a[i][j];
    }
}
console.log(Math.round(det));
