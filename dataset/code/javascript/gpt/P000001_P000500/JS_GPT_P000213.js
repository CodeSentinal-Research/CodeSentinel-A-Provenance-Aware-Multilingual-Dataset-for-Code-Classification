// P000213 - Third Maximum Number
const fs = require("fs");
const tokens = fs.readFileSync(0, "utf8").trim().split(/\s+/).map(Number);
let p = 0;
const n = tokens[p++];
const a = tokens.slice(p, p + n);
const uniq = Array.from(new Set(a)).sort((x, y) => y - x);
console.log(uniq.length >= 3 ? uniq[2] : uniq[0]);
