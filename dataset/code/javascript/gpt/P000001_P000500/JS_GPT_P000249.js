// P000249 - Multiply Two Matrices
const fs = require("fs");
const tokens = fs.readFileSync(0, "utf8").trim().split(/\s+/).map(Number);
let p = 0;
const r1 = tokens[p++], c1 = tokens[p++], r2 = tokens[p++], c2 = tokens[p++];
const A = Array.from({length: r1}, () => tokens.slice(p, p += c1));
const B = Array.from({length: r2}, () => tokens.slice(p, p += c2));
for (let i = 0; i < r1; i++) {
    const row = [];
    for (let j = 0; j < c2; j++) {
        let sum = 0;
        for (let k = 0; k < c1; k++) sum += A[i][k] * B[k][j];
        row.push(sum);
    }
    console.log(row.join(" "));
}
