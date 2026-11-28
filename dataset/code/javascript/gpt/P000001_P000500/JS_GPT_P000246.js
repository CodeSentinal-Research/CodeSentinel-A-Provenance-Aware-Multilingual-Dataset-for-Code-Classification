// P000246 - Print Upper Triangular Matrix
const fs = require("fs");
const tokens = fs.readFileSync(0, "utf8").trim().split(/\s+/).map(Number);
let p = 0;
const n = tokens[p++];
const a = Array.from({length: n}, () => tokens.slice(p, p += n));
for (let i = 0; i < n; i++) {
    const row = [];
    for (let j = 0; j < n; j++) row.push(j >= i ? a[i][j] : 0);
    console.log(row.join(" "));
}
