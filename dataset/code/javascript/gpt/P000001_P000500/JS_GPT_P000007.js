const fs = require("fs");
const n = Number(fs.readFileSync(0, "utf8").trim());
// P000007 - Check Even or Odd
console.log(n % 2 === 0 ? "Even" : "Odd");
