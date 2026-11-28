const fs = require("fs");
const [a, b] = fs.readFileSync(0, "utf8").trim().split(/\s+/).map(Number);
// P000002 - Subtract Two Numbers
console.log(a - b);
