const fs = require("fs");
const [a, b] = fs.readFileSync(0, "utf8").trim().split(/\s+/).map(Number);
// P000047 - Find Quotient and Remainder
console.log(Math.trunc(a / b), a % b);
