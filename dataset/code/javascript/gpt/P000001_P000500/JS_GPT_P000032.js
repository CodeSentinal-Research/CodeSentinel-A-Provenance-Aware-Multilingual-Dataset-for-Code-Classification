const fs = require("fs");
const n = Number(fs.readFileSync(0, "utf8").trim());
// P000032 - Print All Factors
const factors = [];
for (let i = 1; i <= n; i++) {
    if (n % i === 0) factors.push(i);
}
console.log(factors.join(" "));
