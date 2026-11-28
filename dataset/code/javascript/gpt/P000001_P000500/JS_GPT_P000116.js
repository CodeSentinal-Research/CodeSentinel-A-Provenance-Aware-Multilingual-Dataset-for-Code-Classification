// P000116 - Find Missing Number
const fs = require("fs");
const tokens = fs.readFileSync(0, "utf8").trim().split(/\s+/).map(Number);
let p = 0;
const n = tokens[p++];
const a = tokens.slice(p, p + n);
const expected = (n * (n + 1)) / 2;
const actual = a.reduce((s, x) => s + x, 0);
console.log(expected - actual);
