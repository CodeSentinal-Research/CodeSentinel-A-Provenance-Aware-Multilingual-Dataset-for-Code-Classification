// P000139 - Intersection of Two Arrays
const fs = require("fs");
const tokens = fs.readFileSync(0, "utf8").trim().split(/\s+/).map(Number);
let p = 0;
const m = tokens[p++], n = tokens[p++];
const a = tokens.slice(p, p + m); p += m;
const b = tokens.slice(p, p + n);
const setA = new Set(a), setB = new Set(b);
const inter = Array.from(setA).filter(x => setB.has(x));
console.log(inter.join(" "));
