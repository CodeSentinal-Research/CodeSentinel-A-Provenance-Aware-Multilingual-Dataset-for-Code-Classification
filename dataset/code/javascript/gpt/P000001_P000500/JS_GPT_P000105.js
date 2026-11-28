// P000105 - Count Even and Odd Elements
const fs = require("fs");
const tokens = fs.readFileSync(0, "utf8").trim().split(/\s+/).map(Number);
let p = 0;
const n = tokens[p++];
const a = tokens.slice(p, p + n);
let evens = 0, odds = 0;
for (const x of a) {
    if (x % 2 === 0) evens++;
    else odds++;
}
console.log(`${evens} ${odds}`);
