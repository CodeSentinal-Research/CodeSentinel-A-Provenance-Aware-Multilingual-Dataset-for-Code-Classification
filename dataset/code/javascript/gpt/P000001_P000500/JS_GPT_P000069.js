const fs = require("fs");
const r = Number(fs.readFileSync(0, "utf8").trim());
// P000069 - Calculate Perimeter of Circle
const pi = 3.14159;
console.log(2 * pi * r);
