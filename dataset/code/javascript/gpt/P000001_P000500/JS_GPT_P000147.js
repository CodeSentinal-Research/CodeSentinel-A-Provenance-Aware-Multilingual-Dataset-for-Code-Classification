// P000147 - Print Diagonal Elements of Matrix
const fs = require("fs");
const tokens = fs.readFileSync(0, "utf8").trim().split(/\s+/).map(Number);
let p = 0;
const n = tokens[p++];
const mat = Array.from({length: n}, () => tokens.slice(p, p += n));
const mainDiag = [], antiDiag = [];
for (let i = 0; i < n; i++) {
    mainDiag.push(mat[i][i]);
    antiDiag.push(mat[i][n - 1 - i]);
}
console.log(mainDiag.join(" "));
console.log(antiDiag.join(" "));
