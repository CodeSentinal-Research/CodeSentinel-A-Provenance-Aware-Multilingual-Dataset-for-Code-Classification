// P000119 - Separate Even and Odd Numbers
const fs = require("fs");
const tokens = fs.readFileSync(0, "utf8").trim().split(/\s+/).map(Number);
let p = 0;
const n = tokens[p++];
const a = tokens.slice(p, p + n);
const evens = a.filter(x => x % 2 === 0);
const odds = a.filter(x => x % 2 !== 0);
console.log(evens.concat(odds).join(" "));
