// P000231 - Print Elements in Sorted Order of Matrix
const fs = require("fs");
const tokens = fs.readFileSync(0, "utf8").trim().split(/\s+/).map(Number);
let p = 0;
const n = tokens[p++];
const all = tokens.slice(p, p + n * n).sort((x, y) => x - y);
console.log(all.join(" "));
