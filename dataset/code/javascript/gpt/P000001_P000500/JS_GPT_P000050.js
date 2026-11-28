const fs = require("fs");
const n = Number(fs.readFileSync(0, "utf8").trim());
// P000050 - Find Cube of a Number
console.log(n * n * n);
