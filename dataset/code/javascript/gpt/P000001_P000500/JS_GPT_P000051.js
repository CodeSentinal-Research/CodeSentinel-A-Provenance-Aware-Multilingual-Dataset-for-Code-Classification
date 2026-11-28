const fs = require("fs");
const c = fs.readFileSync(0, "utf8").trim()[0];
// P000051 - Check Uppercase or Lowercase
console.log(c === c.toUpperCase() ? "Uppercase" : "Lowercase");
