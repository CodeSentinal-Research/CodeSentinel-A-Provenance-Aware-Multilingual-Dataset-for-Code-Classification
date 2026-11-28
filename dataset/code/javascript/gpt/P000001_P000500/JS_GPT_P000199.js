// P000199 - Find the Element with Odd Occurrence
const fs = require("fs");
const tokens = fs.readFileSync(0, "utf8").trim().split(/\s+/).map(Number);
let p = 0;
const n = tokens[p++];
const a = tokens.slice(p, p + n);
let xor = 0;
for (const x of a) xor ^= x;
console.log(xor);
