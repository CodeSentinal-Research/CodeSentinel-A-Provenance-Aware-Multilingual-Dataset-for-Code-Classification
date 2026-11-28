// P000244 - Maximum Sum Path in Matrix
const fs = require("fs");
const tokens = fs.readFileSync(0, "utf8").trim().split(/\s+/).map(Number);
let p = 0;
const r = tokens[p++], c = tokens[p++];
const a = Array.from({length: r}, () => tokens.slice(p, p += c));
const dp = Array.from({length: r}, () => Array(c).fill(0));
for (let i = 0; i < r; i++) {
    for (let j = 0; j < c; j++) {
        if (i === 0 && j === 0) dp[i][j] = a[i][j];
        else {
            const fromTop = i > 0 ? dp[i - 1][j] : -Infinity;
            const fromLeft = j > 0 ? dp[i][j - 1] : -Infinity;
            dp[i][j] = a[i][j] + Math.max(fromTop, fromLeft);
        }
    }
}
console.log(dp[r - 1][c - 1]);
