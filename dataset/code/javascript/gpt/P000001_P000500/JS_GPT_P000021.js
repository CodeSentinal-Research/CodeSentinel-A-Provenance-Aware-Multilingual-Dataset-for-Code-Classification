const fs = require("fs");
const n = Number(fs.readFileSync(0, "utf8").trim());
// P000021 - Factorial of a Number
let fact = 1;
for (let i = 2; i <= n; i++) fact *= i;
console.log(fact);
