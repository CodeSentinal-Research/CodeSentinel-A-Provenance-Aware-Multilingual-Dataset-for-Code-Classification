// P000104 - Average of Array Elements
const fs = require("fs");
const tokens = fs.readFileSync(0, "utf8").trim().split(/\s+/).map(Number);
let p = 0;
const n = tokens[p++];
const a = tokens.slice(p, p + n);
const sum = a.reduce((s, x) => s + x, 0);
console.log(n ? sum / n : 0);
