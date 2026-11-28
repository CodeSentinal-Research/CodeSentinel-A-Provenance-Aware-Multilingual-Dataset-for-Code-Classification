const fs = require("fs");
const [P, R, T] = fs.readFileSync(0, "utf8").trim().split(/\s+/).map(Number);
// P000038 - Calculate Compound Interest
const ci = P * Math.pow(1 + R / 100, T) - P;
console.log(ci);
