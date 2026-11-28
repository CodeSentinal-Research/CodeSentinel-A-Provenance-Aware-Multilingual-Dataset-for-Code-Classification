const fs = require("fs");
const [x, n] = fs.readFileSync(0, "utf8").trim().split(/\s+/).map(Number);
// P000028 - Power of a Number
console.log(Math.pow(x, n));
