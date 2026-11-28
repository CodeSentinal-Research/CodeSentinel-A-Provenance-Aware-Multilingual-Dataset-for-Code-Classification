// P000110 - Count Frequency of an Element
const fs = require("fs");
const tokens = fs.readFileSync(0, "utf8").trim().split(/\s+/).map(Number);
let p = 0;
const n = tokens[p++], target = tokens[p++];
const a = tokens.slice(p, p + n);
let count = 0;
for (const x of a) if (x === target) count++;
console.log(count);
