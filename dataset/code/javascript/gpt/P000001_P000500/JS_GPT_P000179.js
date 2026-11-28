// P000179 - Relative Sort Array
const fs = require("fs");
const tokens = fs.readFileSync(0, "utf8").trim().split(/\s+/).map(Number);
let p = 0;
const m = tokens[p++], n = tokens[p++];
const a = tokens.slice(p, p + m); p += m;
const b = tokens.slice(p, p + n);
const order = new Map();
b.forEach((v, idx) => order.set(v, idx));
const inB = a.filter(x => order.has(x)).sort((x, y) => order.get(x) - order.get(y));
const notInB = a.filter(x => !order.has(x)).sort((x, y) => x - y);
console.log(inB.concat(notInB).join(" "));
