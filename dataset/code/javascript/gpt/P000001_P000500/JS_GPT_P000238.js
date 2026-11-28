// P000238 - Check if Matrix is Orthogonal
const fs = require("fs");
const tokens = fs.readFileSync(0, "utf8").trim().split(/\s+/).map(Number);
let p = 0;
const n = tokens[p++];
const a = Array.from({length: n}, () => tokens.slice(p, p += n));
let ok = true;
for (let i = 0; i < n; i++) {
    for (let j = 0; j < n; j++) {
        let sum = 0;
        for (let k = 0; k < n; k++) sum += a[k][i] * a[k][j];
        const expected = (i === j ? 1 : 0);
        if (Math.abs(sum - expected) > 1e-6) { ok = false; break; }
    }
    if (!ok) break;
}
console.log(ok ? "Yes" : "No");
