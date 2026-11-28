const fs = require("fs");
const [a, b] = fs.readFileSync(0, "utf8").trim().split(/\s+/).map(Number);
// P000046 - Check Divisibility
console.log(a % b === 0 ? "Divisible" : "Not Divisible");
