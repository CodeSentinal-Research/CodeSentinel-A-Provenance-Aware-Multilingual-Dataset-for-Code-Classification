const fs = require("fs");
const n = Number(fs.readFileSync(0, "utf8").trim());
// P000035 - Check Perfect Number
let sum = 0;
for (let i = 1; i < n; i++) { if (n % i === 0) sum += i; }
console.log(sum === n ? "Perfect" : "Not Perfect");
