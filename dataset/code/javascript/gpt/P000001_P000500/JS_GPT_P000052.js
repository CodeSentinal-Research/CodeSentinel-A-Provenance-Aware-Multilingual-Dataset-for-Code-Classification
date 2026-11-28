const fs = require("fs");
const c = fs.readFileSync(0, "utf8").trim()[0];
// P000052 - Convert Uppercase to Lowercase
console.log(c.toLowerCase());
