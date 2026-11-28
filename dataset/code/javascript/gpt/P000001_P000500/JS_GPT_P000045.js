const fs = require("fs");
const n = Number(fs.readFileSync(0, "utf8").trim());
// P000045 - Sum of Squares of First N Numbers
console.log(n * (n + 1) * (2 * n + 1) / 6);
