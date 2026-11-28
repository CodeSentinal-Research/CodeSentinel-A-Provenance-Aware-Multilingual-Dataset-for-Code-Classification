// P000211 - Maximum Product of Three Numbers
const fs = require("fs");
const tokens = fs.readFileSync(0, "utf8").trim().split(/\s+/).map(Number);
let p = 0;
const n = tokens[p++];
const a = tokens.slice(p, p + n).sort((x, y) => x - y);
const prod1 = a[n - 1] * a[n - 2] * a[n - 3];
const prod2 = a[0] * a[1] * a[n - 1];
console.log(Math.max(prod1, prod2));
