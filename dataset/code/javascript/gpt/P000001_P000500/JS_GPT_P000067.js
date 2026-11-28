const fs = require("fs");
const side = Number(fs.readFileSync(0, "utf8").trim());
// P000067 - Calculate Area of Square
console.log(side * side);
