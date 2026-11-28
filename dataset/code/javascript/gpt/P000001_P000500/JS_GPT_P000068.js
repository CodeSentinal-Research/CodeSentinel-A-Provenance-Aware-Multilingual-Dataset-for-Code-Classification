const fs = require("fs");
const side = Number(fs.readFileSync(0, "utf8").trim());
// P000068 - Calculate Perimeter of Square
console.log(4 * side);
