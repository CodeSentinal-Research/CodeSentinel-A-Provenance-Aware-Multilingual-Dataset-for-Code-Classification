const fs = require("fs");
const side = Number(fs.readFileSync(0, "utf8").trim());
// P000072 - Calculate Volume of Cube
console.log(side * side * side);
