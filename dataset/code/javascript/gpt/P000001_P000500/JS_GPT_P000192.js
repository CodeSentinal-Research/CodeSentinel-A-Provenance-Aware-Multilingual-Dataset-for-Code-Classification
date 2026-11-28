// P000192 - Move All Negative Elements to One Side
const fs = require("fs");
const tokens = fs.readFileSync(0, "utf8").trim().split(/\s+/).map(Number);
let p = 0;
const n = tokens[p++];
const a = tokens.slice(p, p + n);
const neg = a.filter(x => x < 0);
const pos = a.filter(x => x >= 0);
console.log(neg.concat(pos).join(" "));
