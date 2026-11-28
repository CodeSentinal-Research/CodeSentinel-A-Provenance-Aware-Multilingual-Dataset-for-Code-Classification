const fs = require("fs");
const n = Number(fs.readFileSync(0, "utf8").trim());
// P000034 - Sum of Odd Numbers up to N
let sum = 0;
for (let i = 1; i <= n; i += 2) sum += i;
console.log(sum);
