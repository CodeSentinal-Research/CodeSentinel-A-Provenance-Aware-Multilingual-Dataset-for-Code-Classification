// P000141 - Rotate Matrix 90 Degrees Clockwise
const fs = require("fs");
const tokens = fs.readFileSync(0, "utf8").trim().split(/\s+/).map(Number);
let p = 0;
const n = tokens[p++];
const mat = Array.from({length: n}, () => tokens.slice(p, p += n));
for (let i = 0; i < n; i++) {
    for (let j = i + 1; j < n; j++) {
        [mat[i][j], mat[j][i]] = [mat[j][i], mat[i][j]];
    }
}
for (let i = 0; i < n; i++) mat[i].reverse();
for (const row of mat) console.log(row.join(" "));
