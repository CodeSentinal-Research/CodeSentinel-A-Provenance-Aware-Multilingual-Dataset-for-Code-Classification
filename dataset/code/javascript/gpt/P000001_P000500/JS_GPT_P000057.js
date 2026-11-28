const fs = require("fs");
const n = Number(fs.readFileSync(0, "utf8").trim());
// P000057 - Calculate Sum of Series 1+3+5+...+N
console.log(n * n);
