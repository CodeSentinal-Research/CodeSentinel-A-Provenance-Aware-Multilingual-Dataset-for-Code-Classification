// P000111 - Find Second Largest Element
const fs = require("fs");
const tokens = fs.readFileSync(0, "utf8").trim().split(/\s+/).map(Number);
let p = 0;
const n = tokens[p++];
const a = tokens.slice(p, p + n);
const distinct = Array.from(new Set(a)).sort((x, y) => y - x);
console.log(distinct.length >= 2 ? distinct[1] : -1);
