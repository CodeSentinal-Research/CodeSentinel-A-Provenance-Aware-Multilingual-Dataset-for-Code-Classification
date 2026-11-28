// P000115 - Rotate Array Right by K Positions
const fs = require("fs");
const tokens = fs.readFileSync(0, "utf8").trim().split(/\s+/).map(Number);
let p = 0;
const n = tokens[p++], k = tokens[p++];
const a = tokens.slice(p, p + n);
const shift = n ? (k % n) : 0;
const rotated = a.slice(n - shift).concat(a.slice(0, n - shift));
console.log(rotated.join(" "));
