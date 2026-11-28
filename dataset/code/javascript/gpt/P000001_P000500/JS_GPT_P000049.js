const fs = require("fs");
const n = Number(fs.readFileSync(0, "utf8").trim());
// P000049 - Find Square of a Number
console.log(n * n);
