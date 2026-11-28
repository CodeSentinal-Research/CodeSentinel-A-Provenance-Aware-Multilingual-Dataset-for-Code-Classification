const fs = require("fs");
const [base, height] = fs.readFileSync(0, "utf8").trim().split(/\s+/).map(Number);
// P000066 - Calculate Area of Triangle
console.log(0.5 * base * height);
