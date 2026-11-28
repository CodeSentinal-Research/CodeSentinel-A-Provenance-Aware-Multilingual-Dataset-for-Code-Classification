const fs = require("fs");
const n = Number(fs.readFileSync(0, "utf8").trim());
// P000033 - Sum of Even Numbers up to N
let sum = 0;
for (let i = 2; i <= n; i += 2) sum += i;
console.log(sum);
