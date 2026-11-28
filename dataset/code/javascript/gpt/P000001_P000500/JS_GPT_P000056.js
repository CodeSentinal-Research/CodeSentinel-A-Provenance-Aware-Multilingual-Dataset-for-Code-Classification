const fs = require("fs");
const n = Number(fs.readFileSync(0, "utf8").trim());
// P000056 - Calculate Sum of Series 1+2+3+...+N
console.log(n * (n + 1) / 2);
