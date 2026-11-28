// P000172 - Segregate Even and Odd
const fs = require("fs");
const tokens = fs.readFileSync(0, "utf8").trim().split(/\s+/).map(Number);
let p = 0;
const n = tokens[p++];
const a = tokens.slice(p, p + n);
const evens = [], odds = [];
for (let i = 0; i < n; i++) {
    if (Math.abs(a[i]) % 2 === 0) evens.push(a[i]);
    else odds.push(a[i]);
}
console.log(evens.concat(odds).join(" "));
