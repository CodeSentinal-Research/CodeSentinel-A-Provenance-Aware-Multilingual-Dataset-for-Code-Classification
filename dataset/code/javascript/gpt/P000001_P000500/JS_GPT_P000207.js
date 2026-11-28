// P000207 - Maximum Sum of Hourglass in Matrix
const fs = require("fs");
const tokens = fs.readFileSync(0, "utf8").trim().split(/\s+/).map(Number);
let p = 0;
const rows = tokens[p++], cols = tokens[p++];
const a = Array.from({length: rows}, () => tokens.slice(p, p += cols));
let best = -Infinity;
for (let i = 0; i + 2 < rows; i++) {
    for (let j = 0; j + 2 < cols; j++) {
        const sum = a[i][j] + a[i][j+1] + a[i][j+2]
                  + a[i+1][j+1]
                  + a[i+2][j] + a[i+2][j+1] + a[i+2][j+2];
        best = Math.max(best, sum);
    }
}
console.log(best);
