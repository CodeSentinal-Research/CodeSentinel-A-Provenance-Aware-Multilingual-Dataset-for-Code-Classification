const fs = require("fs");
const input = fs.readFileSync(0, "utf8").trim().split(/\s+/).map(Number);
const [a, b] = input;
// P000001 - Add Two Numbers
console.log(a + b);
