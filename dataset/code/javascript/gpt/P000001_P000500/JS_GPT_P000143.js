// P000143 - Transpose of a Matrix
const fs = require("fs");
const tokens = fs.readFileSync(0, "utf8").trim().split(/\s+/).map(Number);
let p = 0;
const rows = tokens[p++], cols = tokens[p++];
const mat = Array.from({length: rows}, () => tokens.slice(p, p += cols));
for (let j = 0; j < cols; j++) {
    const colVals = [];
    for (let i = 0; i < rows; i++) colVals.push(mat[i][j]);
    console.log(colVals.join(" "));
}
