// P000148 - Check if Matrix is Symmetric
const fs = require("fs");
const tokens = fs.readFileSync(0, "utf8").trim().split(/\s+/).map(Number);
let p = 0;
const n = tokens[p++];
const mat = Array.from({length: n}, () => tokens.slice(p, p += n));
let symmetric = true;
for (let i = 0; i < n; i++) {
    for (let j = i + 1; j < n; j++) {
        if (mat[i][j] !== mat[j][i]) { symmetric = false; break; }
    }
    if (!symmetric) break;
}
console.log(symmetric ? "Symmetric" : "Not Symmetric");
