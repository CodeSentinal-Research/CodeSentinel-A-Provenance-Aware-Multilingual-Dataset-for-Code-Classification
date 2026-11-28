// P000145 - Search a 2D Matrix
const fs = require("fs");
const tokens = fs.readFileSync(0, "utf8").trim().split(/\s+/).map(Number);
let p = 0;
const rows = tokens[p++], cols = tokens[p++], target = tokens[p++];
const mat = Array.from({length: rows}, () => tokens.slice(p, p += cols));
let found = false;
let r = 0, c = cols - 1;
while (r < rows && c >= 0) {
    if (mat[r][c] === target) { found = true; break; }
    if (mat[r][c] > target) c--;
    else r++;
}
console.log(found ? "Found" : "Not Found");
