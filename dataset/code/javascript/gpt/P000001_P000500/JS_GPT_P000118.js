// P000118 - Move All Zeroes to End
const fs = require("fs");
const tokens = fs.readFileSync(0, "utf8").trim().split(/\s+/).map(Number);
let p = 0;
const n = tokens[p++];
const a = tokens.slice(p, p + n);
const nonZeros = a.filter(x => x !== 0);
const zeros = Array(n - nonZeros.length).fill(0);
console.log(nonZeros.concat(zeros).join(" "));
