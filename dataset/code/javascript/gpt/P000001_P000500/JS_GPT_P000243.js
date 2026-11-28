// P000243 - Search in a Sorted Matrix Efficiently
const fs = require("fs");
const tokens = fs.readFileSync(0, "utf8").trim().split(/\s+/).map(Number);
let p = 0;
const r = tokens[p++], c = tokens[p++], t = tokens[p++];
const a = Array.from({length: r}, () => tokens.slice(p, p += c));
let i = 0, j = c - 1, found = false;
while (i < r && j >= 0) {
    if (a[i][j] === t) { found = true; break; }
    if (a[i][j] > t) j--;
    else i++;
}
console.log(found ? "Found" : "Not Found");
