// P000151 - Find Maximum Product of Two Elements
const fs = require("fs");
const tokens = fs.readFileSync(0, "utf8").trim().split(/\s+/).map(Number);
let p = 0;
const n = tokens[p++];
const a = tokens.slice(p, p + n).sort((x, y) => x - y);
const prod1 = a[n - 1] * a[n - 2];
const prod2 = a[0] * a[1];
console.log(Math.max(prod1, prod2));
