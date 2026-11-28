// P000146 - Maximum Size Square Submatrix
const fs = require("fs");
const tokens = fs.readFileSync(0, "utf8").trim().split(/\s+/).map(Number);
let p = 0;
const rows = tokens[p++], cols = tokens[p++];
const mat = Array.from({length: rows}, () => tokens.slice(p, p += cols));
const dp = Array.from({length: rows}, () => Array(cols).fill(0));
let maxSide = 0;
for (let i = 0; i < rows; i++) {
    for (let j = 0; j < cols; j++) {
        if (mat[i][j] === 1) {
            if (i === 0 || j === 0) dp[i][j] = 1;
            else dp[i][j] = 1 + Math.min(dp[i - 1][j], dp[i][j - 1], dp[i - 1][j - 1]);
            maxSide = Math.max(maxSide, dp[i][j]);
        }
    }
}
console.log(maxSide);
