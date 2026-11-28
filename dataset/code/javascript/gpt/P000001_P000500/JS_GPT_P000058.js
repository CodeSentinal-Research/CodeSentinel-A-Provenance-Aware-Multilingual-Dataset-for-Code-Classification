const fs = require("fs");
const n = Number(fs.readFileSync(0, "utf8").trim());
// P000058 - Calculate Sum of Series 2+4+6+...+N
console.log(n * (n + 1));
