const fs = require("fs");
let [a, b] = fs.readFileSync(0, "utf8").trim().split(/\s+/).map(Number);
// P000064 - Find HCF of Two Numbers
while (b !== 0) { [a, b] = [b, a % b]; }
console.log(a);
