// P000140 - Union of Two Arrays
const fs = require("fs");
const tokens = fs.readFileSync(0, "utf8").trim().split(/\s+/).map(Number);
let p = 0;
const m = tokens[p++], n = tokens[p++];
const a = tokens.slice(p, p + m); p += m;
const b = tokens.slice(p, p + n);
const union = Array.from(new Set(a.concat(b)));
console.log(union.join(" "));
