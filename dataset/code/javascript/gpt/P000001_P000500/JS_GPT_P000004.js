const fs = require("fs");
const [a, b] = fs.readFileSync(0, "utf8").trim().split(/\s+/).map(Number);
// P000004 - Divide Two Numbers
console.log(Math.trunc(a / b));
