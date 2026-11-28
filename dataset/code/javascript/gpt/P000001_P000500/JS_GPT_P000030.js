const fs = require("fs");
let [a, b] = fs.readFileSync(0, "utf8").trim().split(/\s+/).map(Number);
// P000030 - LCM of Two Numbers
const orig_a = a, orig_b = b;
while (b !== 0) { [a, b] = [b, a % b]; }
const gcd = a;
console.log((orig_a / gcd) * orig_b);
