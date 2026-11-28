const fs = require("fs");
const c = fs.readFileSync(0, "utf8").trim()[0];
// P000053 - Convert Lowercase to Uppercase
console.log(c.toUpperCase());
