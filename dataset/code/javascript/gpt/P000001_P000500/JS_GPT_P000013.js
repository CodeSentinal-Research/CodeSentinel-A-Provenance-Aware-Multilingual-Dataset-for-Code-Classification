const fs = require("fs");
const r = Number(fs.readFileSync(0, "utf8").trim());
// P000013 - Calculate Area of Circle
const pi = 3.14159;
console.log(pi * r * r);
